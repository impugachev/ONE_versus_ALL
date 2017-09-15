//
// Created by igor on 08.09.17.
//

#include "Weapon.h"

Weapon::Weapon(int capacity) :
capacity(capacity), ammo(capacity) {};

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

void Weapon::flyBullets()
{
 /* std::for_each(bullets.begin(), bullets.end(), [&](Bullet &b) {
    if(b.go())
      bullets.erase(b);

  });*/
  for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    if(iter->go() != /*пустой Living*/)
      // то ударить этот Living и удалить пульку

  }
}



