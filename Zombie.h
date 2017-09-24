#ifndef ONE_VERSUS_ALL_MONSTER_H
#define ONE_VERSUS_ALL_MONSTER_H

#include "Living.h"

class Hero;

class Zombie : public Living // Класс зомби
{
private:
  sf::Vector2f randPosition(); // Случайная позиция появления
public:
  Zombie();
  Zombie(int HP, int speed, int damage);
  Zombie(int HP, int speed, int damage, const std::string& textureFile, float centerX, float centerY);
  void rotateToHero(Hero*); // Повернуться к герою
  void runToHero(Hero*); // Идти к герою
  virtual void attack(Living *hero, sf::RenderWindow &) override; // Атаковать
  virtual bool getDamage(int dmg) override; // Получить повреждения
  friend std::ostream& operator<<(std::ostream& out, const Zombie& zombie); // Вывод данных о зомби
  virtual ~Zombie() = default; // Виртуальны деструктор для правильного удаления производных объектов
};

#endif