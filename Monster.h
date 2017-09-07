#ifndef SOURCE_MONSTER_H
#define SOURCE_MONSTER_H

class Monster
{
public:
  unsigned int speed, HP, damage;
  virtual unsigned int attack() = 0;
  virtual void getDamage(unsigned int);
  virtual ~Monster() = default;
  //void move();
};

#endif
