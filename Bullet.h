#ifndef ONE_VERSUS_ALL_BULLET_H
#define ONE_VERSUS_ALL_BULLET_H

#include <SFML/Graphics.hpp>

class Zombie;
class Hero;

class Bullet // Класс "Пуля"
{
private:
  int          speed;     // Скорость пули
  sf::Texture  texture;   // Текстура
  sf::Vector2f from;      // Откуда выпущена
  sf::Vector2i to;        // Куда выпущена
public:
  sf::Sprite   objSprite; // Спрайт
  Bullet(sf::Vector2f from, sf::Vector2i to);
  std::vector<Zombie *>::iterator go(std::vector<Zombie *> &monsters); // Обработка полета пули и попадания
  Hero* go(Hero* hero); // Перегрузка для монстров
  ~Bullet() = default;
};

#endif