//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_MONSTER_H
#define ONE_VERSUS_ALL_MONSTER_H


#include "Living.h"
#include "Hero.h"

class Monster : public Living
{
public:
  Monster();
  Monster(qty HP, qty speed, qty damage, const std::string& textureFile);
  void rotateToHero(Hero*);
  virtual void runToHero(Hero*);
  virtual bool attack(Living *hero);
  virtual void getDamage(qty dmg);
  //~Monster();
};


#endif //ONE_VERSUS_ALL_MONSTER_H
