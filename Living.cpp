#include "Living.h"

const sf::Vector2f & getPosition(Living *living)
{
  return living->objSprite.getPosition();
}

Living::Living(int HP, int speed, int damage,
               const std::string &textureFile, float centerX, float centerY)
    :HP(HP), speed(speed), damage(damage)
{
  texture.loadFromFile(textureFile);
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  objSprite.setOrigin(centerX, centerY);
}

const sf::Vector2f &Living::getPosition()
{
  return this->objSprite.getPosition();
}