#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1024, 768), "ONE versus ALL", sf::Style::Close);
  Game game;
  while
  while (game.window.isOpen())
  {
    sf::Event event;
    while (game.window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        game.window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
      game.saveGame("/home/igor/CLionProjects/ONE_versus_ALL/save");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9))
      game.loadGame("/home/igor/CLionProjects/ONE_versus_ALL/save");
    game.updateHero();
    game.updateEnemies();
    game.updateBullets();
    game.outToDisplay();
  }
  return 0;
}