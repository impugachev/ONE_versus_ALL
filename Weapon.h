//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_WEAPON_H
#define ONE_VERSUS_ALL_WEAPON_H

#include <SFML/Graphics.hpp>
#include "support.h"
#include "Bullet.h"
#include <vector>

class Weapon
{
  friend class Hero;
  friend class Soldier;
private:
  qty ammo, capacity;
  std::vector<Bullet> bullets;
public:
  Weapon(qty capacity);
  bool shoot(sf::Vector2f from, sf::Vector2f to);
  bool isEmpty();
  Weapon& operator-- (int);
};


#endif //ONE_VERSUS_ALL_WEAPON_H
