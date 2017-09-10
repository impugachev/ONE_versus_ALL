//
// Created by igor on 08.09.17.
//

#include "Monster.h"

Monster::Monster()
{

}

Monster::Monster(qty HP, qty speed, qty damage, const std::string& textureFile, sf::Vector2i* position)
: HP(HP), speed(speed), damage(damage), textureFile(textureFile), position(*position)
{
  texture.loadFromFile(textureFile);
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  objSprite.move(position->x, position->y);
}


