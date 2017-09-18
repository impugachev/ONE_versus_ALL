//
// Created by igor on 08.09.17.
//
#include "Soldier.h"
#include "Hero.h"

Soldier::Soldier()
    :Zombie(20, 1, 10, "/home/igor/CLionProjects/ONE_versus_ALL/img/soldier.png",20, 70),gun(10, this) {}

Soldier::Soldier(int HP, int speed, int damage, int capacityWeapon)
    :Zombie(HP, speed, damage, "/home/igor/CLionProjects/ONE_versus_ALL/img/soldier.png",20, 70), gun(capacityWeapon, this)
{
//текстурку и ее центр тут и выше надо еще поставить
}

Soldier::Soldier(int HP, int speed, int damage, const std::string &textureFile, int capacityWeapon, float centerX, float centerY)
    : Zombie(HP, speed, damage, textureFile, centerX, centerY), gun(capacityWeapon, this){}

void Soldier::attack(Living *hero)
{
  // может она и не нужна в базовом классе?
}

void Soldier::getDamage(int dmg)
{
  if (dmg >= HP)
    delete this;
  HP -= dmg;
}

void Soldier::reloadWeapon()
{
  gun.ammo = gun.capacity;
}

void Soldier::shoot(sf::RenderWindow &window, Hero* player)
{
  if (this->gun.isEmpty())
    return;
  gun--;
  sf::Vector2i *playerPos = new sf::Vector2i(player->objSprite.getPosition().x, player->objSprite.getPosition().y);
  gun.shoot(this->getPosition(), *playerPos);
}
