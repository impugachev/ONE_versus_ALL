//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_MONSTER_H
#define ONE_VERSUS_ALL_MONSTER_H

#include "Hero.h"

class Monster : public Living
{
private:
  sf::Vector2f randPosition();
public:
  Monster();
  Monster(int HP, int speed, int damage);
  Monster(int HP, int speed, int damage, const std::string& textureFile, float centerX, float centerY);
  void rotateToHero(Hero*);
  /*virtual*/ void runToHero(Hero*);
  virtual void attack(Living *hero);
  virtual void getDamage(int dmg);
  //~Monster();
};


#endif //ONE_VERSUS_ALL_MONSTER_H
