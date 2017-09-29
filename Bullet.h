#ifndef ONE_VERSUS_ALL_BULLET_H
#define ONE_VERSUS_ALL_BULLET_H

#include <SFML/Graphics.hpp>
#include "Living.h"

class Zombie;
class Hero;

class Bullet // Класс "Пуля"
{
private:
  int          speed;     // Скорость пули
  double       radians;   // Направление в радианах
  sf::Texture  texture;   // Текстура
  sf::Vector2f from;      // Откуда выпущена
public:
  sf::Sprite   objSprite; // Спрайт
  Bullet(sf::Vector2f from, Living *whose);
  std::vector<Zombie *>::iterator go(std::vector<Zombie *> &monsters, Living *hero); // Обработка полета пули и попадания
  Hero* go(Hero* hero); // Перегрузка для монстров
  ~Bullet() = default;
};

#endif