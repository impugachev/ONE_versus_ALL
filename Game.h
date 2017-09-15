//
// Created by igor on 10.09.17.
//

#ifndef ONE_VERSUS_ALL_GAME_H
#define ONE_VERSUS_ALL_GAME_H


//#include <SFML/Graphics.hpp>
//#include "Zombie.h"
#include "Soldier.h"

class Game
{
private:
  sf::Texture background;
  sf::Sprite back;
  Hero player;
  std::vector<Zombie*> monsters;
  sf::Clock timerSpawnZombies, timerSpawnSoldiers, timerAttackMonsters, reload, timerHeroShoot;
public:
  sf::RenderWindow window;
  Game();
  void updateHero();
  void updateEnemies();
  void updateBullets();
  void outToDisplay();
};


#endif //ONE_VERSUS_ALL_GAME_H
