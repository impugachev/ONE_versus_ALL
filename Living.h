#ifndef ONE_VERSUS_ALL_LIVING_H
#define ONE_VERSUS_ALL_LIVING_H

#include "support.h"

class Living
{
protected:
  qty HP, speed, damage;
public:
  virtual bool attack(Living *) = 0;
  virtual void getDamage(qty dmg) = 0;
  virtual ~Living() = default;
};


#endif
