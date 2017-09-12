//
// Created by igor on 08.09.17.
//

#include "Weapon.h"

Weapon::Weapon(qty capacity) :
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



