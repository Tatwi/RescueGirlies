//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "audio/sound_manager.hpp"
#include "badguy/bomb.hpp"
#include "badguy/totem.hpp"
#include "object/explosion.hpp"
#include "object/player.hpp"
#include "sprite/sprite.hpp"
#include "sprite/sprite_manager.hpp"
#include "supertux/object_factory.hpp"
#include "supertux/sector.hpp"
#include "util/reader.hpp"
#include "badguy/captainsnowball.hpp"

namespace{
  static const float CAPTAIN_WALK_SPEED = 60; 
  static const float BOARDING_SPEED = 100;
  static const float JET_TIME = 0.8;
  static const  float JET_YSPEED = -300;
  static const  float JET_XSPEED = 10;
  static const  float RECHARGE_TIME = 3;
  static const  float CLOSE_P_DISTANCE = 160;
  static const  float ENGAGE_HEIGHT = -256;	
}

Totem::Totem(const Reader& reader) :
  WalkingBadguy(reader, "images/creatures/totem/totem.sprite", "walking-left", "walking-right"),
  grabbed(),
  timer(), 
  state(WALKING)
{
  walk_speed = BOARDING_SPEED;
  max_drop_height = -1; // originally 16
  grabbed = false;

  //Prevent stutter when Tux jumps on Mr Bomb
  sound_manager->preload("sounds/explosion.wav");
  sound_manager->preload("sounds/fallingbomb.ogg");
  sound_manager->preload("sounds/fizz.wav");

  //Check if we need another sprite
  if( !reader.get( "sprite", sprite_name ) ){
    return;
  }
  if( sprite_name == "" ){
    sprite_name = "images/creatures/totem/totem.sprite";
    return;
  }
  //Replace sprite
  sprite = sprite_manager->create( sprite_name );
}

/* Totem created by a dispenser always gets default sprite atm.*/
Totem::Totem(const Vector& pos, Direction d) :
  WalkingBadguy(pos, d, "images/creatures/totem/totem.sprite", "walking-left", "walking-right"),
  grabbed(),
  timer(), 
  state(WALKING)
{
  walk_speed = BOARDING_SPEED;
  max_drop_height = -1; // originally 16
  grabbed = false;
  sound_manager->preload("sounds/explosion.wav");
}

HitResponse
Totem::collision(GameObject& object, const CollisionHit& hit)
{
  if(grabbed)
    return FORCE_MOVE;
  return WalkingBadguy::collision(object, hit);
}

HitResponse
Totem::collision_player(Player& player, const CollisionHit& hit)
{
  if(grabbed)
    return FORCE_MOVE;
  return WalkingBadguy::collision_player(player, hit);
}

bool
Totem::collision_squished(GameObject& object)
{
  Player* player = dynamic_cast<Player*>(&object);
  if(player && player->is_invincible()) {
    player->bounce(*this);
    kill_fall();
    return true;
  }
  if(is_valid()) {
    remove_me();
    Sector::current()->add_object(new Bomb(get_pos(), dir, sprite_name ));
  }
  kill_squished(object);
  return true;
}

bool
Totem::might_climb(int width, int height)
{
  // make sure we check for at least a 1-pixel climb
  assert(height > 0);

  float x1;
  float x2;
  float y1a = bbox.p1.y + 1;
  float y2a = bbox.p2.y - 1;
  float y1b = bbox.p1.y + 1 - height;
  float y2b = bbox.p2.y - 1 - height;
  if (dir == LEFT) {
    x1 = bbox.p1.x - width;
    x2 = bbox.p1.x - 1;
  } else {
    x1 = bbox.p2.x + 1;
    x2 = bbox.p2.x + width;
  }
  return ((!Sector::current()->is_free_of_statics(Rectf(x1, y1a, x2, y2a))) && 
          (Sector::current()->is_free_of_statics(Rectf(x1, y1b, x2, y2b))));
}

void
Totem::active_update(float elapsed_time)
{
  if(grabbed)
    return;
  if(frozen){
      WalkingBadguy::active_update(elapsed_time);
    return;
  }
  
	// If on the ground, hop up over obsticals.
	if (on_ground() && might_climb(1, 64)) {
		physic.set_velocity_y(-400);
		WalkingBadguy::active_update(elapsed_time);
		return;
	} else if (on_ground() && might_fall(64)) {
		physic.set_velocity_y(-400);
		walk_speed = BOARDING_SPEED;
		physic.set_velocity_x(dir == LEFT ? -walk_speed : walk_speed);
		WalkingBadguy::active_update(elapsed_time);
		return;
	}
	
	// Play sound to warn player of bombs falling from above.
	if(!on_ground() && physic.get_velocity_y() >= 430 && physic.get_velocity_y() <= 450){
		//only played if fall is greater than 3 blocks.
		sound_manager->play("sounds/fallingbomb.ogg", get_pos());
		WalkingBadguy::active_update(elapsed_time);
		return;
	}
	
	// Setup tools to be used in all states
	Player* player = this->get_nearest_player();
	MovingObject* badguy = this;
	bool close_p = false; // Player close?
	bool facing_p = false; // Facing Player?
	bool under_p = false; // Under Player?
	
	if (state == WALKING){
		WalkingBadguy::active_update(elapsed_time);
		if (on_ground()){
			walk_speed = 60;
		}
		// Setup information about our relationship with Player.
		if (player){
			const Vector playerPos = player->get_pos();
			const Vector badguyPos = badguy->get_pos();
			float dx = (playerPos.x - badguyPos.x);
			float dy = (playerPos.y - badguyPos.y);
				// If Player is left of Totem, dx is negative. If Player is right of Totem, dx is positive.
				// If Player above Totem dy is negative. If Player is below Totem, dy is postive.
			
			if ((badguyPos.x < playerPos.x && physic.get_velocity_x() > 0) ||
			(badguyPos.x > playerPos.x && physic.get_velocity_x() < 0)){
				facing_p = true; // We are facing Player.
			} 
			if ((dx < playerPos.x) && (dx <= CLOSE_P_DISTANCE && dx >= CLOSE_P_DISTANCE * -1) 
			&& (dy <= -32 && dy >= ENGAGE_HEIGHT)){
				close_p = true; // We are close to Player.
			}
			if ((dy <= -70 && dy >= ENGAGE_HEIGHT)) {
				under_p = true; // We are under Player.
				/* 
				If Player <= 2 blocks higher while ducking, Totem will not engage jets. 
				This makes for better game play, especially in areas with low ceilings.
				I originally had it at -32, one block, but it was unjustly annoying to 
				stomp them in the spike pit of level 4. Not impossible, just annoying.
				Note that this also enable the player to crawl-jump on to Totem without
				Totem engaging his jets. Pretty slick way to beat them. :)
				*/
			} 
		}
		
		if (on_ground() && close_p && facing_p && under_p){
			// Use jet boots to fly up if we are near the player.
			walk_speed = JET_XSPEED; // Slow down forward movement to clime better.
			sprite->set_action(dir == LEFT ? "jets-left" : "jets-right");
			sound_manager->play("sounds/fizz.wav", get_pos());
			timer.start(JET_TIME);
			state = JETS;
		}
        }
	
	if (state == JETS){
		WalkingBadguy::active_update(elapsed_time);
		physic.set_velocity_y(JET_YSPEED);
		if (timer.check()) {
			sprite->set_action(dir == LEFT ? "walking-left" : "walking-right"); 
			timer.start(RECHARGE_TIME);
			state = RECHARGE;
		}
	}
	
	if (state == RECHARGE){
		WalkingBadguy::active_update(elapsed_time);
		//sound_manager->play("sounds/coin.wav");
		if (on_ground()){
			walk_speed = 60;
		}
		if (timer.check()) {
			state = WALKING;
		}
	}
}

void
Totem::collision_solid(const CollisionHit& hit)
{
  // Explode if we hit our head on something hard.
  if (hit.top){
	kill_fall();
 }
	
  if (is_active() && (walk_speed == BOARDING_SPEED)) {
    walk_speed = CAPTAIN_WALK_SPEED;
    physic.set_velocity_x(dir == LEFT ? -walk_speed : walk_speed);
  }
  WalkingBadguy::collision_solid(hit);
}

void
Totem::kill_fall()
{
  if(is_valid()) {
    remove_me();
    Explosion* explosion = new Explosion(get_bbox().get_middle());
    Sector::current()->add_object(explosion);
  }

  run_dead_script();
}

void
Totem::grab(MovingObject&, const Vector& pos, Direction dir)
{
  assert(frozen);
  movement = pos - get_pos();
  this->dir = dir;
  sprite->set_action(dir == LEFT ? "iced-left" : "iced-right");
  set_colgroup_active(COLGROUP_DISABLED);
  grabbed = true;
}

void
Totem::ungrab(MovingObject& , Direction dir)
{
  this->dir = dir;
  set_colgroup_active(COLGROUP_MOVING);
  grabbed = false;
}

void
Totem::freeze()
{
  WalkingBadguy::freeze();
  sprite->set_action(dir == LEFT ? "iced-left" : "iced-right");
  state = WALKING;
}

bool
Totem::is_freezable() const
{
  return true;
}

bool
Totem::is_portable() const
{
  return frozen;
}

/* EOF */
