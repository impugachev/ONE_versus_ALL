#ifndef ONE_VERSUS_ALL_LIVING_H
#define ONE_VERSUS_ALL_LIVING_H

#include <SFML/Graphics.hpp>
#include "support.h"

class Living
{
protected:
  qty HP, speed, damage;
  sf::Texture texture;
  const std::string textureFile;
  float centerX;
  float centerY;
public:
  sf::Sprite objSprite;
  Living() = default;
  Living(qty HP, qty speed, qty damage,
         const std::string& textureFile, float centerX, float centerY);

  friend const sf::Vector2f & getPosition(Living* living);
  virtual void attack(Living *) = 0;
  virtual void getDamage(qty dmg) = 0;
  //virtual ~Living() = default;
};


#endif
