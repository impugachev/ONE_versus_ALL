//
// Created by igor on 08.09.17.
//

#include "Weapon.h"

Weapon::Weapon(int capacity, Living* whose)
    : capacity(capacity), ammo(capacity), whose(whose) {};

bool Weapon::isEmpty()
{
  if (this->ammo == 0)
    return true;
  else
    return false;
}

Weapon& Weapon::operator--(int)
{
  this->ammo--;
  return *this;
}

void Weapon::shoot(sf::Vector2f from, sf::Vector2i to)
{
  bullets.emplace_back(from,to);
}

void Weapon::flyBullets(std::vector<Zombie *> *monsters, Hero *hero)
{
  Living* temp;
  for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    temp = iter->go(monsters, hero);
    if (temp != nullptr && temp != whose)
      temp->getDamage(whose->damage);
  }
}



