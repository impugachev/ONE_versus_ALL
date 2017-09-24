#ifndef ONE_VERSUS_ALL_SOLDIER_H
#define ONE_VERSUS_ALL_SOLDIER_H

#include "Zombie.h"
#include "Weapon.h"

class Living;
class Hero;

class Soldier : public Zombie // Класс солдата
{
public:
  Weapon gun; // Оружие солдата
  Soldier();
  Soldier(int HP, int speed, int damage, int capacityWeapon);
  Soldier(int HP, int speed, int damage, const std::string& textureFile, int capacityWeapon,  float centerX, float centerY);
  void attack(Living* hero, sf::RenderWindow&) override; // Атакует героя
  bool getDamage(int dmg) override; // Получает повреждения
  void reloadWeapon(); // Перезарядка оружия
  void shoot(sf::RenderWindow &window, Hero* player); // Выстрелить
  friend std::ostream& operator<<(std::ostream& out, const Soldier& soldier); // Вывод данных о солдате
  ~Soldier() = default;
};

#endif