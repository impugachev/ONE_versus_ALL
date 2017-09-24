#include <fstream>
#include <iostream>
#include "Game.h"
#include "Hero.h"
#include "Soldier.h"

Game::Game()
    :window(sf::VideoMode(1024, 768), "ONE versus ALL", sf::Style::Close), timerSpawnZombies(), timerAttackMonsters(),
     reload(), timerHeroShoot(), reloadSoldier(), monsters(), player()
{
  window.setFramerateLimit(30);
  background.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/background.jpg");
  background.setRepeated(true);
  back = *(new sf::Sprite(background, sf::IntRect(0, 0, 1024, 768)));
  //monsters.push_back(new Zombie());
}

void Game::updateHero()
{
  player.heroControl(window);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    reload.restart();
  if (reload.getElapsedTime().asSeconds() > 3.0 && reload.getElapsedTime().asSeconds() < 3.1)
    player.reloadWeapon();
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && timerHeroShoot.getElapsedTime().asSeconds() > 0.1)
  {
    timerHeroShoot.restart();
    player.shoot(window);
  }
}

void Game::updateEnemies()
{
  if (timerSpawnZombies.getElapsedTime().asSeconds() > 10)
  {
    timerSpawnZombies.restart();
    monsters.push_back(new Zombie());
  }
  if (timerSpawnSoldiers.getElapsedTime().asSeconds() > 30)
  {
    timerSpawnSoldiers.restart();
    monsters.push_back(new Soldier());
  }
  std::for_each(monsters.begin(),monsters.end(),
                [&](Zombie *z)
                {
                  z->rotateToHero(&player);
                  z->runToHero(&player);
                  if (timerAttackMonsters.getElapsedTime().asSeconds() > 2)
                  {
                    z->attack(&player, window);
                    timerAttackMonsters.restart();
                  }
                });
}

void Game::updateBullets()
{
  player.gun.flyBullets(monsters);
  std::for_each(monsters.begin(), monsters.end(),
                [&](Zombie* z) {
                  auto s = dynamic_cast<Soldier *>(z);
                  if (s != NULL)
                  {
                    s->gun.flyBullets(&player);
                    if (s->gun.isEmpty())
                    {
                      reloadSoldier.restart();
                      if (reloadSoldier.getElapsedTime().asSeconds() > 3.0 && reloadSoldier.getElapsedTime().asSeconds() < 3.1)
                        s->reloadWeapon();
                    }
                  }
                });
}

void Game::outToDisplay()
{
  window.clear();
  window.draw(back);
  std::for_each(player.gun.bullets.begin(), player.gun.bullets.end(),
                [&](Bullet* b)
                {
                  window.draw(b->objSprite);
                });
  std::for_each(monsters.begin(), monsters.end(),
                [&](Zombie* z) {
                  auto s = dynamic_cast<Soldier *>(z);
                  if (s != NULL)
                  {
                    std::for_each(s->gun.bullets.begin(), s->gun.bullets.end(),
                                  [&](Bullet* b)
                                  {
                                    window.draw(b->objSprite);
                                  });
                  }
                });
  window.draw(player.objSprite);
  std::for_each(monsters.begin(), monsters.end(), [&](Zombie* z){window.draw(z->objSprite);});
  window.display();
  std::cerr<<player.objSprite.getPosition().x << ' ' << player.objSprite.getPosition().y<<'\n';
}

void Game::loadGame(const char* fileName)
{
  monsters.clear();
  monsters.shrink_to_fit();
  std::fstream savefile(fileName, std::ios::in);
  std::string buffer;
  getline(savefile,buffer);
  buffer == "#SAVE_GAME_ONE_VERSUS_ALL#" ? 0:throw 1;
  getline(savefile,buffer);
  buffer == "Hero" ? 0:throw 1;
  getline(savefile,buffer);
  int *saveHero = new int[6];
  for (int i = 0; i < 6; ++i)
  {
    getline(savefile,buffer);
    size_t posSpace = buffer.find(' ')+1;
    saveHero[i] = std::stoi(buffer.substr(posSpace));
  }
  player = *(new Hero(saveHero[0],saveHero[1],saveHero[2],saveHero[5]));
  player.objSprite.setPosition(saveHero[3], saveHero[4]);
  delete[](saveHero);
  getline(savefile,buffer);
  getline(savefile,buffer);
  if (buffer == "#END_SAVE_FILE#")
    return;
  int numberM = 0;
  if(buffer.substr(0, 6) == "Zombie")
  {
    //std::vector<int*> savesZombie;
    int *saveZombie = new int[5];
    getline(savefile,buffer);
    while (buffer != "##########")
    {
      if (buffer == "**********")
      {
        getline(savefile,buffer);
        getline(savefile,buffer);
      }
      for (int i = 0; i < 5; ++i)
      {
        getline(savefile, buffer);
        size_t posSpace = buffer.find(' ') + 1;
        saveZombie[i] = std::stoi(buffer.substr(posSpace));
      }
      //savesZombie.push_back(saveZombie);
      getline(savefile, buffer);
      monsters.emplace_back(new Zombie(saveZombie[0],saveZombie[1],saveZombie[2]));
      monsters[numberM]->objSprite.setPosition(saveZombie[3],saveZombie[4]);
      ++numberM;
    }
    delete[](saveZombie);
  }
  getline(savefile, buffer);
  if(buffer.substr(0, 7) == "Soldier")
  {
    int *saveSoldier = new int[6];
    getline(savefile,buffer);
    while (buffer != "##########")
    {
      if (buffer == "**********")
      {
        getline(savefile,buffer);
        getline(savefile,buffer);
      }
      for (int i = 0; i < 6; ++i)
      {
        getline(savefile, buffer);
        size_t posSpace = buffer.find(' ') + 1;
        saveSoldier[i] = std::stoi(buffer.substr(posSpace));
      }
      getline(savefile, buffer);
      monsters.emplace_back(new Soldier(saveSoldier[0],saveSoldier[1],saveSoldier[2],saveSoldier[5]));
      monsters[numberM]->objSprite.setPosition(saveSoldier[3],saveSoldier[4]);
      ++numberM;
    }
    delete[](saveSoldier);
  }
}

void Game::saveGame(const char *fileName)
{
  std::fstream saveFile(fileName, std::ios::out);
  saveFile << "#SAVE_GAME_ONE_VERSUS_ALL#\n"
           << "Hero\n"
           << "----------\n"
           << player
           << "##########\n";
  std::vector<Zombie*> zombies = monsters;
  std::vector<Soldier*> soldiers;
  for (auto iter = zombies.begin(); iter != zombies.end(); ++iter)
  {
    auto s = dynamic_cast<Soldier *>(*iter);
    if (s != NULL)
    {
      soldiers.push_back(s);
      zombies.erase(iter--);
    }
  }
  for (int i = 0; i < zombies.size(); ++i)
    saveFile << "Zombie" << i << '\n'
             << "----------\n"
             << *zombies[i]
             << ((i == zombies.size()-1) ? "##########\n" : "**********\n");
  for (int i = 0; i < soldiers.size(); ++i)
    saveFile << "Soldier" << i << '\n'
             << "----------\n"
             << *soldiers[i]
             << ((i == soldiers.size()-1) ? "##########\n" : "**********\n");
  saveFile << "#END_SAVE_FILE#";
}