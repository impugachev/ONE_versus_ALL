//
// Created by igor on 08.09.17.
//

#include "Soldier.h"
#include <cmath>

Soldier::Soldier()
    :Zombie(),gunSoldier(10, this) {}

Soldier::Soldier(int HP, int speed, int damage, int capacityWeapon)
    :Zombie(HP, speed, damage), gunSoldier(capacityWeapon, this)
{
//текстурку и ее центр тут и выше надо еще поставить
}

Soldier::Soldier(int HP, int speed, int damage, const std::string &textureFile, int capacityWeapon, float centerX, float centerY)
    : Zombie(HP, speed, damage, textureFile, centerX, centerY), gunSoldier(capacityWeapon, this){}

void Soldier::attack(Living *hero)
{
  if (this->gunSoldier.isEmpty())
    return;
  gunSoldier--;
  //gunSoldier.shoot()
  //hero->getDamage(damage);
}

void Soldier::getDamage(int dmg)
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
