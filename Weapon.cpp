
#include "Weapon.h"
#include "Bullet.h"
#include "Living.h"
#include "Zombie.h"
#include "Hero.h"

Weapon::Weapon(int capacity, Living* whose)
    : capacity(capacity), ammo(capacity), whose(whose) {};

bool Weapon::isEmpty()
{
  return this->ammo == 0;
}

Weapon& Weapon::operator--(int)
{
  this->ammo--;
  return *this;
}

void Weapon::shoot(sf::Vector2f from, sf::Vector2i to)
{
  bullets.emplace_back(new Bullet(from,to));
}

void Weapon::flyBullets(std::vector<Zombie *> &monsters)
{
  //if (!monsters.empty())
  for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    auto bullet = *iter;
    auto iterToMonster = bullet->go(monsters);
    if (!monsters.empty())
    {
      auto monster = *iterToMonster;
      if (iterToMonster != monsters.end() && monster != whose && monster->getDamage(whose->damage))
      {
        delete(monster);
        monsters.erase(iterToMonster);
      }
    }
    if (bullet->objSprite.getPosition().x > 1024 || bullet->objSprite.getPosition().y > 768 ||
        bullet->objSprite.getPosition().x < 0 || bullet->objSprite.getPosition().y < 0)
    {
      --iter;
      delete(bullet);
      bullets.erase(iter);// вопрос: вызывается ли для этого объекта delete или
      // я правильно сделал, поставив перед ним delete вручную?
    }
  }
}

void Weapon::flyBullets(Hero *hero)
{
  Hero* temp;
  for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    auto bullet = *iter;
    temp = bullet->go(hero);
    if (temp != nullptr && temp != whose)
      temp->getDamage(whose->damage);
    if (bullet->objSprite.getPosition().x > 1024 || bullet->objSprite.getPosition().y > 768 ||
        bullet->objSprite.getPosition().x < 0 || bullet->objSprite.getPosition().y < 0)
    {
      --iter;
      delete(bullet);
      bullets.erase(iter);
    }
  }
}



