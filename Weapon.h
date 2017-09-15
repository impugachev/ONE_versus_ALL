//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_WEAPON_H
#define ONE_VERSUS_ALL_WEAPON_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <vector>

class Weapon
{
  friend class Hero;
  friend class Soldier;
private:
  int ammo, capacity;
  std::vector<Bullet> bullets;
public:
  Weapon(int capacity);
  void shoot(sf::Vector2f from, sf::Vector2i to);
  bool isEmpty();
  Weapon& operator-- (int);
  void flyBullets();
};


#endif //ONE_VERSUS_ALL_WEAPON_H
