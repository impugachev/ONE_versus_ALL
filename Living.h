#ifndef ONE_VERSUS_ALL_LIVING_H
#define ONE_VERSUS_ALL_LIVING_H

typedef unsigned int qty;

class Living
{
protected:
  qty HP, speed, damage;
public:
  virtual unsigned int attack() = 0;
  virtual void getDamage(unsigned int) = 0;
  virtual ~Living() = default;
};

#endif
