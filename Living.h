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
  sf::Sprite objSprite;
  float centerX;
  float centerY;
public:
  friend const sf::Vector2f & getPosition(Living* living);
  virtual void attack(Living *) = 0;
  virtual void getDamage(qty dmg) = 0;
  virtual ~Living() = default;
};


#endif
