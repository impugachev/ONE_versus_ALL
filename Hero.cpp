#include <SFML/Graphics.hpp>
#include <cmath>
#include "Hero.h"

Hero::Hero(qty HP, qty speed, qty damage, qty capacityWeapon,
           const std::string& textureFile, sf::Vector2i* position = new sf::Vector2i(472,319))
: HP(HP), speed(speed), damage(damage), gunHero(capacityWeapon), textureFile(textureFile), position(*position)
{
  texture.loadFromFile(textureFile);
  texture.setSmooth(true);
  objSprite.setTexture(texture);
  objSprite.move(position->x, position->y);
}

void Hero::attack(Living *enemy)
{
  if (this->gunHero.isEmpty())
    return;
  gunHero--;
  //gunHero.shoot()
  //enemy->getDamage(damage);
}

void Hero::heroControl(sf::RenderWindow window)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && position.y > 0 )
  {
    objSprite.move(0, -speed);
    position.y -= speed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y < 768 )
  {
    objSprite.move(0, speed);
    position.y += speed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x > 0 )
  {
    objSprite.move(-speed, 0);
    position.x -= speed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.y < 1024 )
  {
    objSprite.move(speed, 0);
    position.x += speed;
  }
  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
  sf::Vector2i vect = mousePos - position;
  float rot = acos(vect.y/sqrt(vect.x*vect.x+vect.y*vect.y))*180/3.14159265 - 180;
  objSprite.setRotation(vect.x < 0 ? rot : -rot);
}

void Hero::getDamage(qty dmg)
{
  if (dmg >= HP)
  {
    //gameOver
  }
  HP -= dmg;
}

void Hero::reloadWeapon(Weapon& gunHero, sf::Clock& timer)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    timer.restart();
  if(round(timer.getElapsedTime().asSeconds()) == 3)
    gunHero.ammo = gunHero.capacity;
}


