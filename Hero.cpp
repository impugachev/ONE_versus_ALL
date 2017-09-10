//
// Created by igor on 08.09.17.
//

#include <SFML/Graphics.hpp>
#include "Hero.h"

Hero::Hero(qty HP, qty speed, qty damage, qty capacityWeapon, Position* heroPosition = new Position(472,319))
: HP(HP), speed(speed), damage(damage), gunHero(capacityWeapon),heroPosition(*heroPosition)
{
  heroTexture.loadFromFile(imageHero);
  heroTexture.setSmooth(true);
  hero.setTexture(heroTexture);
  hero.move(heroPosition->x, heroPosition->y);
}

bool Hero::attack(Living *enemy)
{
  if (this->gunHero.isEmpty())
    return false;
  gunHero--;
  //gunHero.shoot()
  enemy->getDamage(damage);
}

Position Hero::heroControl()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    hero.move(0, -speed);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    hero.move(0, speed);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    hero.move(-speed, 0);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    hero.move(speed, 0);
  return Position(0, 0);
}
