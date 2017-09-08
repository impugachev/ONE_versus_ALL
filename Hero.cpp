//
// Created by igor on 08.09.17.
//

#include <SFML/Graphics.hpp>
#include "Hero.h"

Hero::Hero(qty HP, qty speed, qty damage, qty capacityWeapon)
: HP(HP), speed(speed), damage(damage), gunHero(capacityWeapon)
{
  heroTexture.loadFromFile(imageHero);
  heroTexture.setSmooth(true);
  hero.setTexture(heroTexture);
  hero.move(472, 319);
}

void Hero::attack(Living *enemy)
{
  enemy->getDamage(damage);
}
