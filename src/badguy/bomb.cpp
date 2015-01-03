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
#include "object/explosion.hpp"
#include "object/player.hpp"
#include "sprite/sprite.hpp"
#include "supertux/sector.hpp"






Bomb::Bomb(const Vector& pos, Direction dir, std::string custom_sprite /*= "images/creatures/mr_bomb/mr_bomb.sprite"*/ ) :
  BadGuy( pos, dir, custom_sprite ), 
  state(),
  grabbed(false), 
  grabber(NULL),
  ticking(),
  on_ground()
{
  state = STATE_TICKING;
  set_action(dir == LEFT ? "ticking-left" : "ticking-right", 1);
  countMe = false;

  ticking.reset(sound_manager->create_sound_source("sounds/fizz.wav"));
  ticking->set_position(get_pos());
  ticking->set_looping(true);
  ticking->set_gain(2.0);
  ticking->set_reference_distance(32);
  ticking->play();
}

void
Bomb::collision_solid(const CollisionHit& hit)
{
  if(hit.top){
	// Fall down if we've been thrown and our head hits 
	// the bottom of a solid surface.
	physic.set_velocity(100, 0);
  }
  if(hit.bottom){
	physic.set_velocity_y(0);
	// Indicate our feet are now on the ground.
	on_ground = true;
  }  

  update_on_ground_flag(hit);
}

HitResponse
Bomb::collision_player(Player& , const CollisionHit& )
{
  return ABORT_MOVE;
}

HitResponse
Bomb::collision_badguy(BadGuy& , const CollisionHit& )
{
  return ABORT_MOVE;
}


void
Bomb::active_update(float elapsed_time)
{
  ticking->set_position(get_pos());
	
  if (state == STATE_TICKING && !grabbed && on_ground){
	// Stop moving when we land, after we've been thrown
	physic.set_velocity(0, 0);
  }
	
  if(sprite->animation_done()) {
    explode();
  }
  else if (!grabbed) {
    movement = physic.get_movement(elapsed_time);
  }
}

void
Bomb::explode()
{
  ticking->stop();

  // Make the player let go before we explode, otherwise the player is holding
  // an invalid object. There's probably a better way to do this than in the
  // Bomb class.
  if (grabber != NULL) {
    Player* player = dynamic_cast<Player*>(grabber);
    
    if (player)
      player->stop_grabbing();
  }

  if(is_valid()) {
    remove_me();
    Explosion* explosion = new Explosion(get_bbox().get_middle());
    Sector::current()->add_object(explosion);
  }

  run_dead_script();
}

void
Bomb::kill_fall()
{
  explode();
}

void
Bomb::grab(MovingObject& object, const Vector& pos, Direction dir)
{
  movement = pos - get_pos();
  this->dir = dir;

  // We actually face the opposite direction of Tux here to make the fuse more
  // visible instead of hiding it behind Tux
  sprite->set_action_continued(dir == LEFT ? "ticking-right" : "ticking-left");
  set_colgroup_active(COLGROUP_DISABLED);
  grabbed = true;
  grabber = &object;
  on_ground = false;
}

void
Bomb::ungrab(MovingObject& object, Direction dir)
{
  this->dir = dir;
  /* In Rescue Girlies, we throw our bombs! 
      Bombs fly in an arc and stop dead when they land on a surface that can be
      walked upon, including steep slopes. */
  physic.set_velocity((dir == RIGHT) ? 200 : -200, -400);
  set_colgroup_active(COLGROUP_MOVING);
  grabbed = false;
}



/* EOF */
