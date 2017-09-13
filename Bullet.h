#ifndef ONE_VERSUS_ALL_BULLET_H
#define ONE_VERSUS_ALL_BULLET_H


#include <SFML/Graphics.hpp>
#include "support.h"

class Bullet
{
private:
  qty speed;
  sf::Sprite objSprite;
  sf::Texture texture;
  sf::Vector2f from;
  sf::Vector2f to;
public:
  Bullet(sf::Vector2f from, sf::Vector2f to);
  void go();
  //~Bullet();
};


#endif
