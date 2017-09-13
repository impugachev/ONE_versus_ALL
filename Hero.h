#ifndef ONE_VERSUS_ALL_HERO_H
#define ONE_VERSUS_ALL_HERO_H

#include "Living.h"
#include "Weapon.h"

class Hero : public Living
{
private:
  Weapon gunHero;
public:
  Hero(qty HP, qty speed, qty damage, qty capacityWeapon, const std::string& textureFile, float centerX, float centerY);
  void attack(Living *enemy); // атакует врага enemy
  void heroControl(sf::RenderWindow& window); // управление перемещением и взглядом персонажа
  void getDamage(qty dmg); // получение повреждений
  void reloadWeapon(Weapon& gunHero/*, sf::Clock& timer*/); // перезарадка оружия
  //~Hero();
};

#endif
