#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
  Game game; // Создание игры
  game.hello();
  while (game.window.isOpen())
  {
    // Обработка клавиши закрытия окна:
    sf::Event event;
    while (game.window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        game.window.close();
    }
    //****************
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
    {
      game.saveGame("../save");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9))
    {
      game.loadGame("../save");
    }
    try
    {
      game.updateHero();
      game.updateEnemies();
      game.updateBullets();
      game.outToDisplay();
    }
    catch (GameOver g)
    {
      auto screenTexture = new sf::Texture();
      screenTexture->loadFromFile("../img/gameOver.png");
      auto screen = new sf::Sprite(*screenTexture);
      sf::Event *event = new sf::Event();
      while (game.window.pollEvent(*event))
      {
        if (event->type == sf::Event::Closed)
          game.window.close();
      }
      game.window.clear();
      game.window.draw(*screen);
      game.window.display();
    }
  }
  return 0;
}