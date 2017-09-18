//
// Created by igor on 08.09.17.
//
#include "Hero.h"
#include "Zombie.h"
#include <cmath>

Zombie::Zombie()
    :Living(100,3,5,"/home/igor/CLionProjects/ONE_versus_ALL/img/zombie.png", 48, 60)
{
  objSprite.move(randPosition());
}

Zombie::Zombie(int HP, int speed, int damage)
    :Living(HP,speed,damage,"/home/igor/CLionProjects/ONE_versus_ALL/img/zombie.png", 48, 60)
{
  objSprite.move(randPosition());
}

Zombie::Zombie(int HP, int speed, int damage, const std::string& textureFile, float centerX, float centerY)
    : Living(HP, speed, damage, textureFile, centerX, centerY)
{
  objSprite.move(randPosition());
}

void Zombie::rotateToHero(Hero *hero)
{
  auto heroPos = hero->getPosition();
  auto vect = heroPos - this->objSprite.getPosition();
  float rot = acos(vect.y/sqrt(vect.x*vect.x+vect.y*vect.y))*180/3.14159265 - 180;
  this->objSprite.setRotation(vect.x < 0 ? rot : -rot);
}

void Zombie::runToHero(Hero *hero)
{
  auto heroPos = hero->getPosition();
  if ((objSprite.getPosition().x < heroPos.x) && (objSprite.getPosition().y < heroPos.y))
    objSprite.move(speed, speed);
  if ((objSprite.getPosition().x > heroPos.x) && (objSprite.getPosition().y < heroPos.y))
    objSprite.move(-speed, speed);
  if ((objSprite.getPosition().x < heroPos.x) && (objSprite.getPosition().y > heroPos.y))
    objSprite.move(speed, -speed);
  if ((objSprite.getPosition().x > heroPos.x) && (objSprite.getPosition().y > heroPos.y))
    objSprite.move(-speed, -speed);
}

void Zombie::attack(Living *hero)
{
  auto heroPos = hero->getPosition();
  auto monsterPos = objSprite.getPosition();
  if((monsterPos.x-heroPos.x)*(monsterPos.x-heroPos.x)+(monsterPos.y-heroPos.y)*(monsterPos.y-heroPos.y) <= 100)
    hero->getDamage(damage);
}

void Zombie::getDamage(int dmg)
{
  if (dmg >= HP)
    //~Zombie(this);
  HP -= dmg;
}

sf::Vector2f Zombie::randPosition()
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
  return position;
}







