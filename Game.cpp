#include "Game.h"
#include "Hero.h"
#include "Soldier.h"

Game::Game()
    :window(sf::VideoMode(1024, 768), "ONE versus ALL", sf::Style::Close), timerSpawnZombies(), timerAttackMonsters(), reload(), timerHeroShoot(),
     monsters(), player()
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
