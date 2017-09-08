//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_SOLDIER_H
#define ONE_VERSUS_ALL_SOLDIER_H


#include "Monster.h"

class Soldier : public Monster
{
public:
  Soldier(qty HP, qty speed, qty damage);
  void attack(Living* hero);
  void getDamage(qty dmg);
  Position runToHero();
  void reloadWeapon();
  ~Soldier();
};


#endif //ONE_VERSUS_ALL_SOLDIER_H
