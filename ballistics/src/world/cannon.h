#ifndef _CANNON_H_
#define _CANNON_H_

#include <list>
#include "../core/math/transform2.h"
#include "bullet.h"
#include "particle.h"

struct SDL_Renderer;

class cannon
{
public:
  cannon(vec2 position, real_t angle, const bullet *bt, real_t damping, U8 r, U8 g, U8 b);

  void tick();
  void draw(SDL_Renderer *renderer);
  void fire(std::list<particle>& particles) const;
  void set_bullet(const bullet *b);
  void set_angular_velocity(real_t angular_velocity);

private:
  transform2 _transform;
  const bullet *_bullet;  
  real_t _angular_velocity;
  real_t _damping;
  U8 _r;
  U8 _g;
  U8 _b;
};

#endif
