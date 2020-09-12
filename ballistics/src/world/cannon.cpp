#include <list>
#include <cassert>
#include "cannon.h"
#include "../core/config.h"

cannon::cannon(vec2 position, real_t angle, const bullet *b, real_t damping) :
  _transform{angle, position},
  _bullet{b},
  _angular_velocity{0.0},
  _damping{damping}
{}

void cannon::tick()
{
  if(_angular_velocity >= 0.0) {
    _angular_velocity *= _damping;

    // stabalise to 0 if below a small threshold.
    if(_angular_velocity <= 0.3)
      _angular_velocity = 0.0;
    
    _transform.rotate(_angular_velocity * cfg::physics::tick_delta);
  }
}

void cannon::fire(const std::list<particle>& particles) const
{
  std::assert(_bullet != nullptr);

  particle p{
    _transform.get_translation(),
    _transform.transform_direction({_bullet->speed, 0.0}),
    {0.0, _bullet->gravity},
    _bullet->_inverse_mass,
    _bullet->_damping,
    _bullet->_r,
    _bullet->_g,
    _bullet->_b
  };

  particles.push_back(p);
}

void cannon::set_bullet(const bullet *b)
{
  _bullet = b;
}

void cannon::set_angular_velocity(real_t angular_velocity)
{
  _angular_velocity = angular_velocity;
}

