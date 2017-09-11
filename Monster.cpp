//
// Created by igor on 08.09.17.
//

#include <cmath>
#include "Monster.h"

Monster::Monster()
{

}

Monster::Monster(qty HP, qty speed, qty damage, const std::string& textureFile)
: HP(HP), speed(speed), damage(damage), textureFile(textureFile)
{
  texture.loadFromFile(textureFile);
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  srand(time(0));
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
  objSprite.move(position.x, position.y);
}

void Monster::rotateToHero(Hero *hero)
{
  auto heroPos = getPosition(hero);
  auto vect = heroPos - position;
  float rot = acos(vect.y/sqrt(vect.x*vect.x+vect.y*vect.y))*180/3.14159265 - 180;
  objSprite.setRotation(vect.x < 0 ? rot : -rot);
}

void Monster::runToHero(Hero *hero)
{
  auto heroPos = getPosition(hero);
  if ((position.x < heroPos.x) && (position.y < heroPos.y))
  {
    objSprite.move(speed, speed);
    position.x += speed;
    position.y += speed;
  }
  if ((position.x > heroPos.x) && (position.y < heroPos.y))
  {
    objSprite.move(-speed, speed);
    position.x -= speed;
    position.y += speed;
  }
  if ((position.x < heroPos.x) && (position.y > heroPos.y))
  {
    objSprite.move(speed, -speed);
    position.x += speed;
    position.y -= speed;
  }
  if ((position.x > heroPos.x) && (position.y > heroPos.y))
  {
    objSprite.move(-speed, -speed);
    position.x -= speed;
    position.y -= speed;
  }
}

void Monster::attack(Living *hero)
{
if(position - sf::Vector2i(20,20))
}

void Monster::getDamage(qty dmg)
{
  if (dmg >= HP)
    delete this;
  HP -= dmg;
}





