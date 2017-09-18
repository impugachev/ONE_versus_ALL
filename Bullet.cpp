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

Zombie* Bullet::go(std::vector<Zombie *> *monsters) //эта функция должна иметь доступ к тому вектору монстров
{
  objSprite.move(speed,0);
  float y = to.x*from.y-from.x*to.y-(from.y-to.y)*objSprite.getPosition().x;
  //objSprite.move(0,y);
  for (auto &monster : *monsters)
  {
    if((objSprite.getPosition().x- monster->getPosition().x)*(objSprite.getPosition().x- monster->getPosition().x)+
       (objSprite.getPosition().y- monster->getPosition().y)*(objSprite.getPosition().y- monster->getPosition().y) <= 100)
      return monster;
  }

  return nullptr;
}

Hero* Bullet::go(Hero *hero)
{
  objSprite.move(speed,0);
  float y = to.x*from.y-from.x*to.y-(from.y-to.y)*objSprite.getPosition().x;
  objSprite.move(0,y);
  if ((objSprite.getPosition().x-hero->getPosition().x)*(objSprite.getPosition().x-hero->getPosition().x)+
      (objSprite.getPosition().y-hero->getPosition().y)*(objSprite.getPosition().y-hero->getPosition().y) <= 100)
    return hero;
  return nullptr;
}

