//
// Created by igor on 10.09.17.
//

#include "Game.h"

Game::Game()
    :window(sf::VideoMode(1024, 768), "ONE versus ALL"), timerSpawn(), timerAttack(), reload(), timerHero(),
     zombieAndSoldiers(), player()
{
  window.setFramerateLimit(30);
  background.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/background.jpg");
  background.setRepeated(true);
  back = *(new sf::Sprite(background, sf::IntRect(0, 0, 1024, 768)));
}