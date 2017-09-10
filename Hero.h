//
// Created by igor on 08.09.17.
//

#ifndef ONE_VERSUS_ALL_HERO_H
#define ONE_VERSUS_ALL_HERO_H


#include "Living.h"
#include "Weapon.h"

class Hero : public Living
{
private:
  char imageHero[] = "/home/igor/MyProject/ONE_versus_ALL/img/hero.png";
  sf::Texture heroTexture;
  sf::Sprite hero;
  Weapon gunHero;
public:
  Hero(qty HP, qty speed, qty damage, qty capacityWeapon, sf::Vector2i* position = new sf::Vector2i(472,319));
  bool attack(Living *enemy);
  void heroControl(sf::RenderWindow window);
  void getDamage(qty dmg);
  void reloadWeapon(Weapon& gunHero);
  //~Hero();
};


#endif //ONE_VERSUS_ALL_HERO_H
