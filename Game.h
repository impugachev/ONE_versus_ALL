#ifndef ONE_VERSUS_ALL_GAME_H
#define ONE_VERSUS_ALL_GAME_H

class Zombie;

#include <SFML/Graphics.hpp>
#include "Hero.h"

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
  void loadGame(const char* fileName);
  void saveGame(const char* fileName);
};


#endif //ONE_VERSUS_ALL_GAME_H
