//
// Created by igor on 10.09.17.
//

#include "Game.h"
#include "Soldier.h"

Game::Game()
    :window(sf::VideoMode(1024, 768), "ONE versus ALL"), timerSpawnZombies(), timerAttack(), reload(), timerHeroShoot(),
     allMonsters(), player()
{
  window.setFramerateLimit(30);
  background.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/background.jpg");
  background.setRepeated(true);
  back = *(new sf::Sprite(background, sf::IntRect(0, 0, 1024, 768)));
}

void Game::updateHero()
{
  player.heroControl(window);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    reload.restart();
  if (reload.getElapsedTime().asSeconds() > 3.0 && reload.getElapsedTime().asSeconds() < 3.1)
    player.reloadWeapon();
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && timerHeroShoot.getElapsedTime().asSeconds() > 0.5)
  {
    timerHeroShoot.restart();
    player.shoot(window);
//выстрелить
  }
}

void Game::updateEnemies()
{
  if (timerSpawnZombies.getElapsedTime().asSeconds() > 10)
  {
    timerSpawnZombies.restart();
    allMonsters.push_back(new Zombie());
  }
  if (timerSpawnSoldiers.getElapsedTime().asSeconds() > 30)
  {
    timerSpawnSoldiers.restart();
    allMonsters.push_back(new Soldier());
  }
  std::for_each(allMonsters.begin(),allMonsters.end(),
                [&](Zombie *z){
                  z->rotateToHero(&player);
                  z->runToHero(&player);
                  if (timerAttack.getElapsedTime().asSeconds() > 2)
                  {
                    z->attack(&player);
                    timerAttack.restart();
                  }
                  //window.draw(z->objSprite);
                });
}
