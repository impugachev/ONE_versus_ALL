#ifndef ONE_VERSUS_ALL_HERO_H
#define ONE_VERSUS_ALL_HERO_H

#include "Living.h"
#include "Weapon.h"

class Hero : public Living
{
private:
  Weapon gunHero;
public:
  Hero(qty HP, qty speed, qty damage, qty capacityWeapon, const std::string& textureFile,
       sf::Vector2i* position = new sf::Vector2i(512,384));
  bool attack(Living *enemy);
  void heroControl(sf::RenderWindow window);
  void getDamage(qty dmg);
  void reloadWeapon(Weapon& gunHero);
  //~Hero();
};

#endif
