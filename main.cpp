//#include <SFML/Graphics.hpp>
#include <iostream>
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
  sf::Clock timerSpawn, timerAttack, reload, timerHero;
  while (window.isOpen())
  {
    if (timerSpawn.getElapsedTime().asSeconds() > 10)
    {
      timerSpawn.restart();
      monsters.emplace_back(10,2,5,"/home/igor/CLionProjects/ONE_versus_ALL/img/zombie.png", 48, 60);
    }
    hero.heroControl(window);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
      reload.restart();
    if (reload.getElapsedTime().asSeconds() > 3.0 && reload.getElapsedTime().asSeconds() < 3.1)
      hero.reloadWeapon();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && timerHero.getElapsedTime().asSeconds() > 0.5)
    {
      timerHero.restart();
      //hero.attack()
    }
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
    std::cerr << reload.getElapsedTime().asSeconds()<< "\n";
  }
  return 0;
}