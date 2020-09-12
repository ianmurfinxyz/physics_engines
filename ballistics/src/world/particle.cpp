#include "particle.h"
#include "../core/config.h"

particle::particle(real_t inverse_mass, real_t damping) : 
  _position{0.0, 0.0}, 
  _velocity{0.0, 0.0}, 
  _acceleration{0.0, 0.0},
  _inverse_mass{inverse_mass},
  _damping{damping}
{}

particle::particle(vec2 acceleration, real_t inverse_mass, real_t damping) : 
  _position{0.0, 0.0}, 
  _velocity{0.0, 0.0}, 
  _acceleration{acceleration},
  _inverse_mass{inverse_mass} 
  _damping{damping}
{}
                                                             

particle(vec2 position, vec2 velocity, vec2 acceleration, real_t inverse_mass, real_t damping) :
  _position{position}, 
  _velocity{velocity}, 
  _acceleration{acceleration},
  _inverse_mass{inverse_mass} 
  _damping{damping}
{}

void particle::tick()
{
  if(_inverse_mass <= 0.0)
    return;

  // euler integration - ignoring 0.5*acceleration*delta_squared term of position integration.

  _position += _velocity * cfg::physics::tick_delta; 

  _velocity += _acceleration * cfg::physics::tick_delta;
  _velocity *= _damping;
}
