#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
  Game game; // Создание игры
// Блок вывода данных по управлению игрой
  auto screenTexture = new sf::Texture();
  screenTexture->loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/firstScreen.png");
  auto screen = new sf::Sprite(*screenTexture);
  sf::Event *event = new sf::Event();
  while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
  {
    while (game.window.pollEvent(*event))
    {
      if (event->type == sf::Event::Closed)
        game.window.close();
    }
    game.window.clear();
    game.window.draw(*screen);
    game.window.display();
  }
  delete (screenTexture);
  delete (screen);
  delete (event);
// Конец блока
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