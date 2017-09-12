//
// Created by igor on 08.09.17.
//

#include <cmath>
#include "Monster.h"

Monster::Monster()
{

}

Monster::Monster(qty HP, qty speed, qty damage, const std::string& textureFile, float centerX, float centerY)
: Living(HP, speed, damage, textureFile, centerX, centerY)
{
  srand(time(0));
  sf::Vector2f position;
  int randomizePosition = rand() % 4;
  switch (randomizePosition)
  {
    case 0:
      position.x = -20;
      position.y = -20 + rand() % 808;
      break;
    case 1:
      position.x = -20 + rand() % 1064;
      position.y = 788;
      break;
    case 2:
      position.x = 1044;
      position.y = -20 + rand() % 808;
      break;
    case 3:
      position.x = -20 + rand() % 1064;
      position.y = -20;
      break;
  }
  objSprite.move(position);
}

void Monster::rotateToHero(Hero *hero)
{
  auto heroPos = getPosition(hero);
  auto vect = heroPos - this->objSprite.getPosition();
  float rot = acos(vect.y/sqrt(vect.x*vect.x+vect.y*vect.y))*180/3.14159265 - 180;
  this->objSprite.setRotation(vect.x < 0 ? rot : -rot);
}

void Monster::runToHero(Hero *hero)
{
  auto heroPos = getPosition(hero);
  if ((objSprite.getPosition().x < heroPos.x) && (objSprite.getPosition().y < heroPos.y))
    objSprite.move(speed, speed);
  if ((objSprite.getPosition().x > heroPos.x) && (objSprite.getPosition().y < heroPos.y))
    objSprite.move(-speed, speed);
  if ((objSprite.getPosition().x < heroPos.x) && (objSprite.getPosition().y > heroPos.y))
    objSprite.move(speed, -speed);
  if ((objSprite.getPosition().x > heroPos.x) && (objSprite.getPosition().y > heroPos.y))
    objSprite.move(-speed, -speed);
}

void Monster::attack(Living *hero)
{
  auto heroPos = getPosition(hero);
  auto monsterPos = objSprite.getPosition();
  if((monsterPos.x-heroPos.x)*(monsterPos.x-heroPos.x)+(monsterPos.y-heroPos.y)*(monsterPos.y-heroPos.y) <= 100)
    hero->getDamage(damage);
}

void Monster::getDamage(qty dmg)
{
  if (dmg >= HP)
    delete this;
  HP -= dmg;
}





