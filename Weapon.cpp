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
  bullets.push_back(new Bullet(from,to));
}

void Weapon::flyBullets(std::vector<Zombie *> &monsters)
{
  //if (!monsters.empty())
  for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    auto bullet = *iter;
    auto iterToMonster = bullet->go(monsters);
    if (!monsters.empty() && iterToMonster != monsters.end())
    {
      auto monster = *iterToMonster;
      if (iterToMonster != monsters.end() && monster != whose && monster->getDamage(whose->damage))
      {
        delete(monster);
        monsters.erase(iterToMonster);
      }
    }
    // Где же дальше ошибка? В чем проблема????
    //if (bullet->objSprite.getPosition().x > 1024 || bullet->objSprite.getPosition().y > 768 ||
    //    bullet->objSprite.getPosition().x < 0 || bullet->objSprite.getPosition().y < 0)
    //{
    //  delete(bullet);
    //  auto tempIter = bullets.begin();
    //  bullets.erase(iter);// вопрос: вызывается ли для этого объекта delete или
      // я правильно сделал, поставив перед ним delete вручную?
    //  tempIter == iter ? iter = bullets.begin() : iter--;
    //}
  }
}

void Weapon::flyBullets(Hero *hero) //доработать
{
  for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
  {
    auto bullet = *iter;
    auto temp = bullet->go(hero);
    if (temp != nullptr && temp != whose)
      temp->getDamage(whose->damage);
    // Где же дальше ошибка? В чем проблема????
    if (bullet->objSprite.getPosition().x > 1500 || bullet->objSprite.getPosition().y > 1000 ||
        bullet->objSprite.getPosition().x < -100 || bullet->objSprite.getPosition().y < -100)
    {
      //--iter;
      delete(bullet);
      auto tempIter = bullets.begin();
      bullets.erase(iter);
      tempIter == iter ? iter = bullets.begin() : iter--;
    }
  }
}