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

bool Bullet::go() //эта функция должна иметь доступ к тому вектору монстров
{
  objSprite.move(speed,0);
  float y = to.x*from.y-from.x*to.y-(from.y-to.y)*objSprite.getPosition().x;
  objSprite.move(0,y);
  if((objSprite.getPosition().x-monsterPos.x)*(objSprite.getPosition().x-monsterPos.x)+
         (objSprite.getPosition().y-monsterPos.y)*(objSprite.getPosition().y-monsterPos.y) <= 100)
    return true;
  else
    return false;
}
