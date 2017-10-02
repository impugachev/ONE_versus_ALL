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

void Weapon::shoot()
{
  bullets.push_back(new Bullet(whose->getPosition(), whose));
}

void Weapon::flyBullets(std::vector<Zombie *> &monsters)
{
  for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    auto bullet = *iter;
    auto iterToMonster = bullet->go(monsters, whose);
    if (!monsters.empty() && iterToMonster != monsters.end())
    {
      auto monster = *iterToMonster;
      if (iterToMonster != monsters.end() && monster != whose && monster->getDamage(whose->damage))
      {
        delete monster;
        monsters.erase(iterToMonster);
      }
    }
    if (bullet->objSprite.getPosition().x > 1024 || bullet->objSprite.getPosition().y > 768 ||
        bullet->objSprite.getPosition().x < 0 || bullet->objSprite.getPosition().y < 0)
    {
      delete bullet;
      bullets.erase(iter);
      break;
    }
  }
}

void Weapon::flyBullets(Hero *hero)
{
  for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    auto bullet = *iter;
    auto temp = bullet->go(hero);
    if (temp != nullptr && temp != whose)
      temp->getDamage(whose->damage);
    if (bullet->objSprite.getPosition().x > 1500 || bullet->objSprite.getPosition().y > 1000 ||
        bullet->objSprite.getPosition().x < -100 || bullet->objSprite.getPosition().y < -100)
    {
      delete bullet;
      bullets.erase(iter);
      break;
    }
  }
}

Weapon::~Weapon()
{
  for (auto &bullet:bullets)
    delete bullet;
}
