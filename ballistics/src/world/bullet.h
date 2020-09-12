#ifndef _BULLET_H_
#define _BULLET_H_

#include "../core/math/math_defs.h"
#include "../system/types.h"

struct bullet
{
  real_t _speed;
  real_t _inverse_mass;
  real_t _gravity;
  real_t _damping;
  U8 _r;
  U8 _g;
  U8 _b;
};

#endif
