//
// Created by igor on 08.09.17.
//

#include "Living.h"

const sf::Vector2f & getPosition(Living *living)
{
  return living->objSprite.getPosition();
}

Living::Living(qty HP, qty speed, qty damage,
               const std::string &textureFile, float centerX, float centerY)
    :HP(HP), speed(speed), damage(damage), textureFile(textureFile), centerX(centerX), centerY(centerY)
{
  texture.loadFromFile(textureFile);
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  objSprite.setOrigin(centerX, centerY);
}

