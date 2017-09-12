//
// Created by igor on 08.09.17.
//

#include "Soldier.h"
#include <cmath>

Soldier::Soldier(qty HP, qty speed, qty damage, const std::string &textureFile, qty capacityWeapon, float centerX, float centerY)
    : Monster(HP, speed, damage, textureFile, centerX, centerY), gunSoldier(capacityWeapon){}

void Soldier::attack(Living *hero)
{
  if (this->gunSoldier.isEmpty())
    return;
  gunSoldier--;
  //gunSoldier.shoot()
  //hero->getDamage(damage);
}

void Soldier::getDamage(qty dmg)
{
  if (dmg >= HP)
    delete this;
  HP -= dmg;
}

void Soldier::reloadWeapon(Weapon &gunSoldier, sf::Clock& timer)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    timer.restart();
  if(round(timer.getElapsedTime().asSeconds()) == 3)
    gunSoldier.ammo = gunSoldier.capacity;
}

