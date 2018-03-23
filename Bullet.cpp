#include "Bullet.h"
#include "Zombie.h"
#include "Hero.h"
#include <cmath>

Bullet::Bullet(sf::Vector2f from, Living *whose)
    : speed(12)
{
  texture.loadFromFile("../img/bullet.png");
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  objSprite.setOrigin(5, 5);
  objSprite.move(from);
  radians = (whose->objSprite.getRotation() - 90) * M_PI/180;
}

std::vector<Zombie *>::iterator Bullet::go(std::vector<Zombie *> &monsters, Living *hero)
{
  objSprite.move(speed*cos(radians), speed*sin(radians));
  for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
  {
    auto monster = *iter;
    if((objSprite.getPosition().x- monster->getPosition().x)*(objSprite.getPosition().x- monster->getPosition().x)+
       (objSprite.getPosition().y- monster->getPosition().y)*(objSprite.getPosition().y- monster->getPosition().y) <= 400)
      return iter;
  }
  return monsters.end();
}

Hero* Bullet::go(Hero *hero)
{
  objSprite.move(speed*cos(radians), speed*sin(radians));
  if ((objSprite.getPosition().x-hero->getPosition().x)*(objSprite.getPosition().x-hero->getPosition().x)+
      (objSprite.getPosition().y-hero->getPosition().y)*(objSprite.getPosition().y-hero->getPosition().y) <= 400)
    return hero;
  return nullptr;
}