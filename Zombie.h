#ifndef SOURCE_ZOMBIE_H
#define SOURCE_ZOMBIE_H

#include "Monster.h"

class Zombie: public Monster
{
  Zombie();
  ~Zombie();
  unsigned int attack();
};

#endif
