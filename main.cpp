#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
  sf::Clock t;
  Game game;
  while (game.window.isOpen())
  {
    sf::Event event;
    while (game.window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        game.window.close();
    }
    if (t.getElapsedTime().asSeconds() > 10)
    {
      std::cerr<<t.getElapsedTime().asSeconds()<<'\n';
    }
    game.updateHero();
    game.updateEnemies();
    //game.updateBullets();
    game.outToDisplay();
    std::cerr<<t.getElapsedTime().asSeconds()<<'\n';
  }
  return 0;
}