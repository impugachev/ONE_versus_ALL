//#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Monster.h"


int main()
{
  sf::RenderWindow window(sf::VideoMode(1024, 768), "ONE versus ALL");
  window.setFramerateLimit(30);
  Hero hero(1000, 7, 5, 30, "/home/igor/CLionProjects/ONE_versus_ALL/img/hero.png", 30, 70);
  sf::Texture background;
  background.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/background.jpg");
  background.setRepeated(true);
  sf::Sprite back(background, sf::IntRect(0, 0, 1024, 768));
  std::vector<Monster> monsters;
  sf::Clock timerSpawn, timerAttack;
  while (window.isOpen())
  {
    if (timerSpawn.getElapsedTime().asSeconds() > 10)
    {
      timerSpawn.restart();
      monsters.emplace_back(10,2,5,"/home/igor/CLionProjects/ONE_versus_ALL/img/zombie.png", 48, 60);
    }
    hero.heroControl(window);
    window.clear();
    window.draw(back);
    std::for_each(monsters.begin(),monsters.end(),
                  [&](Monster &z){
                    z.rotateToHero(&hero);
                    z.runToHero(&hero);
                    if (timerAttack.getElapsedTime().asSeconds() > 1)
                    {
                      z.attack(&hero);
                      timerAttack.restart();
                    }
                    window.draw(z.objSprite);
                  });
    window.draw(hero.objSprite);
    window.display();
  }
  return 0;
}