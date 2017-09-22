#include <fstream>
//#include <map>
#include "Game.h"
#include "Hero.h"
#include "Soldier.h"


Game::Game()
    :window(sf::VideoMode(1024, 768), "ONE versus ALL", sf::Style::Close), timerSpawnZombies(), timerAttackMonsters(),
     reload(), timerHeroShoot(), monsters(), player()
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
                    s->gun.flyBullets(&player);
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
  player = Hero(saveHero[0],saveHero[1],saveHero[2],saveHero[3]);
  player.objSprite.setPosition(saveHero[4], saveHero[5]);
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
      monsters.emplace_back(new Soldier(saveSoldier[0],saveSoldier[1],saveSoldier[2],saveSoldier[3]));
      monsters[numberM]->objSprite.setPosition(saveSoldier[4],saveSoldier[5]);
      ++numberM;
    }
    delete[](saveSoldier);
  }
}