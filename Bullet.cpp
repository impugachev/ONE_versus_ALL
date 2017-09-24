#include "Bullet.h"
#include "Zombie.h"
#include "Hero.h"

Bullet::Bullet(sf::Vector2f from, sf::Vector2i to)
    : from(from), to(to), speed(10)
{
  texture.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/bullet.png");
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  objSprite.setOrigin(5, 5);
  objSprite.move(from);
}

std::vector<Zombie *>::iterator Bullet::go(std::vector<Zombie *> &monsters)
{
  float y = (from.x*to.y-to.x*from.y-(to.y-from.y)*objSprite.getPosition().x)/(from.x-to.x); // Может с формулой напортачил?
  objSprite.setPosition(objSprite.getPosition().x+((from.x-to.x) < 0 ? speed: -speed),y);
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
  float y = (from.x*to.y-to.x*from.y-(to.y-from.y)*objSprite.getPosition().x)/(from.x-to.x);
  objSprite.setPosition(objSprite.getPosition().x+((from.x-to.x) < 0 ? speed: -speed),y);
  if ((objSprite.getPosition().x-hero->getPosition().x)*(objSprite.getPosition().x-hero->getPosition().x)+
      (objSprite.getPosition().y-hero->getPosition().y)*(objSprite.getPosition().y-hero->getPosition().y) <= 400)
    return hero;
  return nullptr;
}