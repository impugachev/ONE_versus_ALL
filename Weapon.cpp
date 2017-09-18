
#include "Weapon.h"
#include "Bullet.h"
#include "Living.h"
#include "Zombie.h"
#include "Hero.h"

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

void Weapon::flyBullets(std::vector<Zombie *> *monsters)
{
  Living* temp;
  for (auto &bullet : bullets)
  {
    temp = bullet.go(monsters);
    if (temp != nullptr && temp != whose)
      temp->getDamage(whose->damage);
  }
}

void Weapon::flyBullets(Hero *hero)
{
  Living* temp;
  for (auto &bullet : bullets)
  {
    temp = bullet.go(hero);
    if (temp != nullptr && temp != whose)
      temp->getDamage(whose->damage);
  }
}



