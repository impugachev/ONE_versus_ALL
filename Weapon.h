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
  int                  ammo;     // Количество оставшихся боеприпасов
  std::vector<Bullet*> bullets;  // Пули, находящиеся в полете
  Living*              whose;    // Указатель на хозяина оружия
public:
  int                  capacity; // Размер обоймы
  Weapon(int capacity, Living* whose);
  void shoot(sf::Vector2f from, sf::Vector2i to); // Обработка выстрела
  bool isEmpty(); // Проверка на количество оставшихся боеприпасов
  Weapon& operator-- (int); // Боеприпасы -1
  void flyBullets(std::vector<Zombie*> &monsters); // Обработка полета всех пуль героя
  void flyBullets(Hero *hero); // Перегрузка для солдата
};

#endif