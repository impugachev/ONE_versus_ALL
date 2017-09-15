#ifndef ONE_VERSUS_ALL_LIVING_H
#define ONE_VERSUS_ALL_LIVING_H

#include <SFML/Graphics.hpp>

class Living
{
protected:
  int HP, speed, damage;
  sf::Texture texture;
  float centerX;
  float centerY;
public:
  sf::Sprite objSprite;
  Living() = default;
  Living(int HP, int speed, int damage,
         const std::string& textureFile, float centerX, float centerY);

  friend const sf::Vector2f & getPosition(Living* living);
  virtual void attack(Living *) = 0;
  virtual void getDamage(int dmg) = 0;
  //virtual ~Living() = default;
};


#endif
