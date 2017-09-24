#ifndef ONE_VERSUS_ALL_LIVING_H
#define ONE_VERSUS_ALL_LIVING_H

#include <SFML/Graphics.hpp>

class Living             // Общий класс для врагов и героя
{
protected:
  int         HP,        // Очки здоровья
              speed;     // Скорость
  sf::Texture texture;   // Текстура объекта
public:
  int         damage;    // Наносимый урон
  sf::Sprite  objSprite; // Спрайт объекта
  Living() = default;
  Living(int HP, int speed, int damage,
         const std::string& textureFile, float centerX, float centerY);
  const sf::Vector2f & getPosition(); // получить координаты объекта
  friend const sf::Vector2f & getPosition(Living* living); // ||-||-||
  virtual void attack(Living *, sf::RenderWindow &) = 0; // Атаковать
  virtual bool getDamage(int dmg) = 0; // получить повреждения
  virtual ~Living() = default; // виртуальный деструктор для правильного удаления производных объектов
};

#endif