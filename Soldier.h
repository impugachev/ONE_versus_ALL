#ifndef ONE_VERSUS_ALL_SOLDIER_H
#define ONE_VERSUS_ALL_SOLDIER_H

#include "Zombie.h"
#include "Weapon.h"

class Living;
class Hero;

class Soldier : public Zombie
{
public:
  Weapon gun;
  Soldier();
  Soldier(int HP, int speed, int damage, int capacityWeapon);
  Soldier(int HP, int speed, int damage, const std::string& textureFile, int capacityWeapon,  float centerX, float centerY);
  void attack(Living* hero) override;
  void getDamage(int dmg) override;
  void reloadWeapon();
  void shoot(sf::RenderWindow &window, Hero* player);
  //void runToHero(Hero*);
  //~Soldier();
};


#endif //ONE_VERSUS_ALL_SOLDIER_H
