//
// Created by igor on 08.09.17.
//

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f from, sf::Vector2i to)
    : from(from), to(to), speed(10)
{
  texture.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/bullet.png");
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  objSprite.setOrigin(5, 5);
  objSprite.move(from);
}

Living* Bullet::go(std::vector<Zombie *> *monsters, Hero *hero) //эта функция должна иметь доступ к тому вектору монстров
{
  objSprite.move(speed,0);
  float y = to.x*from.y-from.x*to.y-(from.y-to.y)*objSprite.getPosition().x;
  objSprite.move(0,y);
  for (auto iter = monsters->begin(); iter != monsters->end(); ++iter)
  {
    if((objSprite.getPosition().x-(*iter)->getPosition().x)*(objSprite.getPosition().x-(*iter)->getPosition().x)+
       (objSprite.getPosition().y-(*iter)->getPosition().y)*(objSprite.getPosition().y-(*iter)->getPosition().y) <= 100)
      return *iter;
  }
  if ((objSprite.getPosition().x-hero->getPosition().x)*(objSprite.getPosition().x-hero->getPosition().x)+
      (objSprite.getPosition().y-hero->getPosition().y)*(objSprite.getPosition().y-hero->getPosition().y) <= 100)
    return hero;
  return nullptr;
}
