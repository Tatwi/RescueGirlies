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

#ifndef HEADER_SUPERTUX_BADGUY_TOTEM_HPP
#define HEADER_SUPERTUX_BADGUY_TOTEM_HPP

#include "badguy/walking_badguy.hpp"

class Totem : public WalkingBadguy, 
               public Portable
{
public:
  Totem(const Reader& reader);
  Totem(const Vector& pos, Direction d);

  void kill_fall();
  HitResponse collision(GameObject& object, const CollisionHit& hit);
  HitResponse collision_player(Player& player, const CollisionHit& hit);

  bool might_climb(int width, int height);
  void active_update(float elapsed_time);
  void collision_solid(const CollisionHit& hit);

  void grab(MovingObject& object, const Vector& pos, Direction dir);
  void ungrab(MovingObject& object, Direction dir);
  bool is_portable() const;

  void freeze();
  bool is_freezable() const;

protected:
  bool collision_squished(GameObject& object);
  enum TotemState {
    WALKING,
    JETS, 
    RECHARGE
  };

private:
  bool grabbed;
  Timer timer;
  TotemState state;
};

#endif

/* EOF */
