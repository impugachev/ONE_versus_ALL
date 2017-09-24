#ifndef ONE_VERSUS_ALL_HERO_H
#define ONE_VERSUS_ALL_HERO_H

#include "Living.h"
#include "Weapon.h"

class Hero : public Living
{
public:
  Weapon gun; // Оружие героя
  Hero();
  Hero(int HP, int speed, int damage, int capacityWeapon);
  Hero(int HP, int speed, int damage, int capacityWeapon, const std::string& textureFile, float centerX, float centerY);
  void attack(Living *enemy, sf::RenderWindow &) override; // Атакует врага, заменена shoot, возможно необходимо удалить
  void heroControl(sf::RenderWindow& window); // Управление перемещением и взглядом персонажа
  bool getDamage(int dmg) override; // Получение повреждений
  void reloadWeapon(); // Перезарадка оружия
  void shoot(sf::RenderWindow &window); // Выстрелить
  friend std::ostream& operator<<(std::ostream& out, const Hero& hero); // Вывод данных о герое
  ~Hero() = default;
};

#endif