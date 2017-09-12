//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_SOLDIER_H
#define ONE_VERSUS_ALL_SOLDIER_H


#include "Monster.h"

class Soldier : public Monster
{
private:
  Weapon gunSoldier;
public:
  Soldier(qty HP, qty speed, qty damage, const std::string& textureFile, qty capacityWeapon,  float centerX, float centerY);
  void attack(Living* hero);
  void getDamage(qty dmg);
  void reloadWeapon(Weapon& gunSoldier, sf::Clock& timer);
  //void runToHero(Hero*);
  //~Soldier();
};


#endif //ONE_VERSUS_ALL_SOLDIER_H
