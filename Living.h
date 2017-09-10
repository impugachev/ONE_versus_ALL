#ifndef ONE_VERSUS_ALL_LIVING_H
#define ONE_VERSUS_ALL_LIVING_H

#include <SFML/Graphics.hpp>
#include "support.h"

class Living
{
protected:
  qty HP, speed, damage;
  sf::Vector2i position;
public:
  virtual bool attack(Living *) = 0;
  virtual void getDamage(qty dmg) = 0;
  virtual ~Living() = default;
};


#endif
