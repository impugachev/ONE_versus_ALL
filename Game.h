//
// Created by igor on 10.09.17.
//

#ifndef ONE_VERSUS_ALL_GAME_H
#define ONE_VERSUS_ALL_GAME_H


#include <SFML/Graphics.hpp>
#include "Monster.h"

class Game
{
private:
  sf::Texture background;
  sf::Sprite back;
  Hero player;
  std::vector<Monster*> zombieAndSoldiers;
  sf::Clock timerSpawn, timerAttack, reload, timerHero;
public:
  sf::RenderWindow window;
  Game();
  void updateHero();
  void updateEnemies();
  void updateBullets();
  void outToDisplay();
};


#endif //ONE_VERSUS_ALL_GAME_H
