#include "Soldier.h"
#include "Hero.h"

Soldier::Soldier()
    :Zombie(20, 1, 10, "../img/soldier.png",20, 70),gun(10, this) {}

Soldier::Soldier(int HP, int speed, int damage, int capacityWeapon)
    :Zombie(HP, speed, damage, "../img/soldier.png",20, 70), gun(capacityWeapon, this) {}

Soldier::Soldier(int HP, int speed, int damage, const std::string &textureFile, int capacityWeapon, float centerX, float centerY)
    : Zombie(HP, speed, damage, textureFile, centerX, centerY), gun(capacityWeapon, this){}

void Soldier::attack(Living* hero, sf::RenderWindow& window)
{
  auto player = dynamic_cast<Hero*>(hero);
  this->shoot(window,player);
}

bool Soldier::getDamage(int dmg)
{
  if (dmg >= HP)
    return true;
  HP -= dmg;
  return false;
}

void Soldier::reloadWeapon()
{
  gun.ammo = gun.capacity;
}

void Soldier::shoot(sf::RenderWindow &window, Hero* player)
{
  if (this->gun.isEmpty())
    return;
  gun--;
  auto *playerPos = new sf::Vector2i(player->objSprite.getPosition().x, player->objSprite.getPosition().y);
  gun.shoot();
}

std::ostream &operator<<(std::ostream &out, const Soldier &soldier)
{
  out << "HP " <<soldier.HP << '\n'
      << "speed " << soldier.speed << '\n'
      << "damage " << soldier.damage << '\n'
      << "positionX " << soldier.objSprite.getPosition().x << '\n'
      << "positionY " << soldier.objSprite.getPosition().y << '\n'
      << "capacityWeapon " << soldier.gun.capacity << '\n';
  return out;
}