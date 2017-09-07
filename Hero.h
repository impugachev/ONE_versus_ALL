#ifndef ONE_VERSUS_ALL_HERO_H
#define ONE_VERSUS_ALL_HERO_H

#include "Living.h"

class Hero : public Living
{
public:
  Hero(qty HP, qty speed, qty damage);
};

#endif //ONE_VERSUS_ALL_HERO_H
