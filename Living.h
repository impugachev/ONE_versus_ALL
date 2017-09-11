#ifndef ONE_VERSUS_ALL_LIVING_H
#define ONE_VERSUS_ALL_LIVING_H

#include <SFML/Graphics.hpp>
#include "support.h"

class Living
{
protected:
  qty HP, speed, damage;
  sf::Texture texture;
  sf::Vector2i position;
  const std::string textureFile;
  sf::Sprite objSprite;
public:
  friend sf::Vector2i getPosition(Living* living);
  virtual bool attack(Living *) = 0;
  virtual void getDamage(qty dmg) = 0;
  virtual ~Living() = default;
};


#endif
