//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_WEAPON_H
#define ONE_VERSUS_ALL_WEAPON_H


#include "support.h"
#include "Hero.h"
#include "Soldier.h"

class Weapon
{
  friend Hero;
  friend Soldier;
private:
  qty ammo, capacity;
public:
  Weapon(qty capacity);
  bool shoot(position from, position to);
};


#endif //ONE_VERSUS_ALL_WEAPON_H
