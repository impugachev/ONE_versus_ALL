//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_MONSTER_H
#define ONE_VERSUS_ALL_MONSTER_H

#include "Living.h"
class Hero;

class Zombie : public Living
{
private:
  sf::Vector2f randPosition();
public:
  Zombie();
  Zombie(int HP, int speed, int damage);
  Zombie(int HP, int speed, int damage, const std::string& textureFile, float centerX, float centerY);
  void rotateToHero(Hero*);
  /*virtual*/ void runToHero(Hero*);
  virtual void attack(Living *hero, sf::RenderWindow &);
  virtual bool getDamage(int dmg);
  friend std::ostream& operator<<(std::ostream& out, const Zombie& zombie);
  //~Zombie();
};


#endif //ONE_VERSUS_ALL_MONSTER_H
