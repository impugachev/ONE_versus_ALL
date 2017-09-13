//
// Created by igor on 08.09.17.
//

#include "Bullet.h"

Bullet::Bullet(qty speed, sf::Vector2f from, sf::Vector2f to)
    : speed(speed), from(from), to(to)
{
  texture.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/bullet.png");
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  objSprite.setOrigin(5, 5);
  objSprite.move(from);
}

void Bullet::go()
{
  objSprite.move(speed,0);
  float y = to.x*from.y-from.x*to.y-(from.y-to.y)*objSprite.getPosition().x;
  objSprite.move(0,y);
}
