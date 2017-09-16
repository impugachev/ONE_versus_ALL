#ifndef ONE_VERSUS_ALL_BULLET_H
#define ONE_VERSUS_ALL_BULLET_H


#include <SFML/Graphics.hpp>

class Zombie;
class Hero;

class Bullet
{
private:
  int speed;
  sf::Texture texture;
  sf::Vector2f from;
  sf::Vector2i to;
public:
  sf::Sprite objSprite;
  Bullet(sf::Vector2f from, sf::Vector2i to);
  Zombie* go(std::vector<Zombie *> *monsters);
  Hero* go(Hero* hero);
  //~Bullet();
};


#endif
