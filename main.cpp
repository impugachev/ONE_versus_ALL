#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
  Game game;
  while (game.window.isOpen())
  {
    sf::Event event;
    while (game.window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        game.window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9))
      game.loadGame("/home/igor/CLionProjects/ONE_versus_ALL/save");
    game.updateHero();
    game.updateEnemies();
    game.updateBullets();
    game.outToDisplay();
  }
  return 0;
}