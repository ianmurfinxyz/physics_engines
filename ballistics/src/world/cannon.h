#ifndef _CANNON_H_
#define _CANNON_H_

#include "../core/math/transform2.h"

class cannon
{
public:
  cannon(vec2 position, real_t angle, const bullet *b, real_t damping);

  void tick();
  void fire() const;
  void set_bullet(const bullet *b);
  void set_angular_velocity(real_t angular_velocity);

private:
  transform2 _transform;
  const bullet *_bullet;  
  real_t _angular_velocity;
  real_t _damping;
};

#endif
