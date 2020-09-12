#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "../core/math/vector2.h"
#include "../core/math/units.h"
#include "../system/types.h"

class particle
{
public:
  particle(real_t inverse_mass, real_t damping);
  particle(vec2 acceleration, real_t inverse_mass, real_t damping);
  particle(vec2 position, vec2 velocity, vec2 acceleration, real_t inverse_mass, real_t damping, U8 r, U8 g, U8 b);

  void tick()

private:
  vec2 _position;
  vec2 _velocity;
  vec2 _acceleration;
  real_t _inverse_mass;
  real_t _damping;
  U8 _r;
  U8 _g;
  U8 _b;
};

#endif
