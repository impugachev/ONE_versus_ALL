#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
  Game game("/home/igor/CLionProjects/ONE_versus_ALL/save");
  while (game.window.isOpen())
  {
    sf::Event event;
    while (game.window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        game.window.close();
    }
    game.updateHero();
    game.updateEnemies();
    game.updateBullets();
    game.outToDisplay();
  }
  return 0;
}