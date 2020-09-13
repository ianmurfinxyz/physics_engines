#include <SDL2/SDL.h>
#include "particle.h"
#include "../core/config.h"

particle::particle(real_t inverse_mass, real_t damping) : 
  _position{0.0, 0.0}, 
  _velocity{0.0, 0.0}, 
  _acceleration{0.0, 0.0},
  _radius{1.f},
  _inverse_mass{inverse_mass},
  _damping{damping},
  _age{0.0},
  _r{255},
  _g{255},
  _b{255}
{}

particle::particle(vec2 acceleration, real_t inverse_mass, real_t damping) : 
  _position{0.0, 0.0}, 
  _velocity{0.0, 0.0}, 
  _acceleration{acceleration},
  _radius{1.f},
  _inverse_mass{inverse_mass},
  _damping{damping},
  _age{0.0},
  _r{255},
  _g{255},
  _b{255}
{}
                                                             

particle::particle(vec2 position, vec2 velocity, vec2 acceleration, real_t radius, real_t inverse_mass, real_t damping, U8 r, U8 g, U8 b) :
  _position{position}, 
  _velocity{velocity}, 
  _acceleration{acceleration},
  _radius{radius},
  _inverse_mass{inverse_mass},
  _damping{damping},
  _age{0.0},
  _r{r},
  _g{g},
  _b{b}
{}

void particle::tick()
{
  if(_inverse_mass <= 0.0)
    return;

  // euler integration - ignoring 0.5*acceleration*delta_squared term of position integration.

  _position += _velocity * cfg::physics::tick_delta; 

  _velocity += _acceleration * cfg::physics::tick_delta;
  _velocity *= _damping;

  _age += cfg::physics::tick_delta;
}

void particle::draw(SDL_Renderer *renderer)
{
  SDL_Rect rect;
  rect.x = _position.x - _radius;
  rect.y = _position.y - _radius;
  rect.w = _radius * 2.0;
  rect.h = rect.w;

  SDL_SetRenderDrawColor(renderer, _r, _g, _b, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(renderer, &rect);
}
