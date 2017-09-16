#ifndef ONE_VERSUS_ALL_HERO_H
#define ONE_VERSUS_ALL_HERO_H

#include "Living.h"
#include "Weapon.h"

class Hero : public Living
{
public:
  Weapon gun;
  Hero();
  Hero(int HP, int speed, int damage, int capacityWeapon);
  Hero(int HP, int speed, int damage, int capacityWeapon, const std::string& textureFile, float centerX, float centerY);
  void attack(Living *enemy); // атакует врага enemy
  void heroControl(sf::RenderWindow& window); // управление перемещением и взглядом персонажа
  void getDamage(int dmg); // получение повреждений
  void reloadWeapon(/*Weapon& gun, sf::Clock& timer*/); // перезарадка оружия
  void shoot(sf::RenderWindow &window);
  //~Hero();
};

#endif
