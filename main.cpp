//#include <SFML/Graphics.hpp>
#include "Hero.h"


int main()
{
  sf::RenderWindow window(sf::VideoMode(1024, 768), "ONE versus ALL");
  window.setFramerateLimit(30);
  Hero hero(10, 5, 5, 30, "/home/igor/CLionProjects/ONE_versus_ALL/img/hero.png", 30, 70);
  sf::Texture background;
  background.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/background.jpg");
  background.setRepeated(true);
  sf::Sprite back(background, sf::IntRect(0, 0, 1024, 768));
  while (window.isOpen())
  {
    hero.heroControl(window);
    window.clear();
    window.draw(back);
    window.draw(hero.objSprite);
    window.display();
  }
  return 0;
}