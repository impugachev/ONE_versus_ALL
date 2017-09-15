#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Hero.h"

Hero::Hero()
    : Living(100, 7, 5, "/home/igor/CLionProjects/ONE_versus_ALL/img/hero.png", 30, 70), gunHero(10, this)
{
  objSprite.move(472, 319);
}

Hero::Hero(int HP, int speed, int damage, int capacityWeapon)
    :Living(HP, speed, damage, "/home/igor/CLionProjects/ONE_versus_ALL/img/hero.png", 30, 70), gunHero(capacityWeapon, this)
{
  objSprite.move(472, 319);
}

Hero::Hero(int HP, int speed, int damage, int capacityWeapon,
           const std::string& textureFile, float centerX, float centerY)
    : Living(HP, speed, damage, textureFile, centerX, centerY), gunHero(capacityWeapon, this)
{
  objSprite.move(472, 319);
}

void Hero::attack(Living *enemy)
{
  if (this->gunHero.isEmpty())
    return;
  gunHero--;
  //gunHero.shoot()
  //enemy->getDamage(damage);
}

void Hero::heroControl(sf::RenderWindow& window)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && objSprite.getPosition().y > 0 )
    objSprite.move(0, -speed);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && objSprite.getPosition().y < 768 )
    objSprite.move(0, speed);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && objSprite.getPosition().x > 0 )
    objSprite.move(-speed, 0);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && objSprite.getPosition().x < 1024 )
    objSprite.move(speed, 0);
  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
  sf::Vector2i vect(mousePos.x - objSprite.getPosition().x, mousePos.y - objSprite.getPosition().y);
  float rot = acos(vect.y/sqrt(vect.x*vect.x+vect.y*vect.y))*180/3.14159265 - 180;
  objSprite.setRotation(vect.x < 0 ? rot : -rot);
}

void Hero::getDamage(int dmg)
{
  if (dmg >= HP)
  {
    std::cerr<<"gameover";
    delete this;
    //gameOver
  }
  std::cerr<<"damage\n";
  HP -= dmg;
}

void Hero::reloadWeapon()
{
    gunHero.ammo = gunHero.capacity;
}

void Hero::shoot(sf::RenderWindow &window)
{
  if (this->gunHero.isEmpty())
    return;
  gunHero--;
  gunHero.shoot(getPosition(this), sf::Mouse::getPosition(window));
}






