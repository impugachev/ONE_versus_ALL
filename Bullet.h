#ifndef ONE_VERSUS_ALL_BULLET_H
#define ONE_VERSUS_ALL_BULLET_H


#include <SFML/Graphics.hpp>

class Bullet
{
private:
  int speed;
  sf::Sprite objSprite;
  sf::Texture texture;
  sf::Vector2f from;
  sf::Vector2i to;
public:
  Bullet(sf::Vector2f from, sf::Vector2i to);
  bool go();
  //~Bullet();
};


#endif
