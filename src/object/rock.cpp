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
#include "object/rock.hpp"
#include "supertux/object_factory.hpp"
#include "supertux/tile.hpp"
#include "badguy/badguy.hpp"
#include "object/player.hpp"

#include "object/explosion.hpp"
#include "object/broken_brick.hpp"
#include "sprite/sprite_manager.hpp"
#include "supertux/sector.hpp"
#include "sprite/sprite.hpp"

namespace {
const std::string ROCK_SOUND = "sounds/rock.wav"; 
}

Rock::Rock(const Vector& pos, std::string spritename) :
  MovingSprite(pos, spritename),
  physic(),
  on_ground(),
  grabbed(),
  last_movement()
{
  sound_manager->preload(ROCK_SOUND);
  on_ground = false;
  grabbed = false;
  set_group(COLGROUP_MOVING_STATIC);
}

Rock::Rock(const Reader& reader) :
  MovingSprite(reader, "images/objects/rock/rock.sprite"),
  physic(),
  on_ground(),
  grabbed(),
  last_movement()
{
  sound_manager->preload(ROCK_SOUND);
  on_ground = false;
  grabbed = false;
  set_group(COLGROUP_MOVING_STATIC);
}

Rock::Rock(const Reader& reader, std::string spritename) :
  MovingSprite(reader, spritename),
  physic(),
  on_ground(),
  grabbed(),
  last_movement()
{
  sound_manager->preload(ROCK_SOUND);
  on_ground = false;
  grabbed = false;
  set_group(COLGROUP_MOVING_STATIC);
}

void
Rock::update(float elapsed_time)
{
  if( grabbed )
    return;

  if (on_ground) physic.set_velocity_x(0);

  movement = physic.get_movement(elapsed_time);
}

void
Rock::collision_solid(const CollisionHit& hit)
{
  if(grabbed) {
    return;
  }
  if(hit.top || hit.bottom)
    physic.set_velocity_y(0);
  if(hit.left || hit.right)
    physic.set_velocity_x(0);
  if(hit.crush)
    physic.set_velocity(0, 0);

  if(hit.bottom  && !on_ground && !grabbed) {
    sound_manager->play(ROCK_SOUND, get_pos());
    on_ground = true;
  }
}

HitResponse
Rock::collision(GameObject& other, const CollisionHit& hit)
{
  if(grabbed) {
    return ABORT_MOVE;
  }
   // Blow up if hit by an explosion.
   Explosion* explosion = dynamic_cast<Explosion*> (&other);
   if(explosion) {
	  Sector* sector = Sector::current();
	  sector->add_object(
	    new BrokenBrick(sprite->clone(), get_pos(), Vector(-100, -400)));
	  sector->add_object(
	    new BrokenBrick(sprite->clone(), get_pos() + Vector(0, 16),
			    Vector(-150, -300)));
	  sector->add_object(
	    new BrokenBrick(sprite->clone(), get_pos() + Vector(16, 0),
			    Vector(100, -400)));
	  sector->add_object(
	    new BrokenBrick(sprite->clone(), get_pos() + Vector(16, 16),
			    Vector(150, -300)));
	  remove_me();
   }	 
  
  if(!on_ground) {
	Player* player = dynamic_cast<Player*> (&other);
	if(player) {
		return FORCE_MOVE;
       }
	  
    if(hit.bottom && physic.get_velocity_y() > 200) {
	BadGuy* badguy = dynamic_cast<BadGuy*> (&other);
	if(badguy) {
		//Getting a rock on the head hurts. A lot. If you're an enemy! :)
		badguy->collision_tile(Tile::HURTS);
	}
    }
    return FORCE_MOVE;
  }
  return FORCE_MOVE;
}

void
Rock::grab(MovingObject& , const Vector& pos, Direction)
{
  movement = pos - get_pos();
  last_movement = movement;
  set_group(COLGROUP_TOUCHABLE); //needed for lanterns catching willowisps
  on_ground = false;
  grabbed = true;
}

void
Rock::ungrab(MovingObject& , Direction dir)
{
  set_group(COLGROUP_MOVING_STATIC);
  on_ground = false;
  if(dir == UP) {
    physic.set_velocity(0, -500);
  } else if (last_movement.norm() > 1) {
    physic.set_velocity((dir == RIGHT) ? 200 : -200, -200);
  } else {
    physic.set_velocity(0, 0);
  }
  grabbed = false;
}


/* EOF */
