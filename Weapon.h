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
private:
  qty ammo, capacity;
public:
  Weapon(qty capacity);
  bool shoot(Position from, Position to);
  bool isEmpty();
  Weapon& operator-- (Weapon& gun);
};


#endif //ONE_VERSUS_ALL_WEAPON_H
