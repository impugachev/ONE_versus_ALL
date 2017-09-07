#ifndef SOURCE_MONSTER_H
#define SOURCE_MONSTER_H

#include "Living.h"

class Monster : public Living
{
public:
  Monster(qty HP, qty speed, qty damage);
  void runToHero();
};

#endif
