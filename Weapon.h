//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_WEAPON_H
#define ONE_VERSUS_ALL_WEAPON_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Living;
class Zombie;
class Hero;

class Weapon
{
  friend class Game;
  friend class Hero;
  friend class Soldier;
private:
  int ammo;
  std::vector<Bullet*> bullets;
  Living* whose;
public:
  int capacity;
  Weapon(int capacity, Living* whose);
  void shoot(sf::Vector2f from, sf::Vector2i to);
  bool isEmpty();
  Weapon& operator-- (int);
  void flyBullets(std::vector<Zombie*> &monsters);
  void flyBullets(Hero *hero);
};


#endif //ONE_VERSUS_ALL_WEAPON_H
