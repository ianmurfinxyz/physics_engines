#include <SDL2/SDL.h>
#include <cassert>
#include <cmath>
#include "cannon.h"
#include "../core/config.h"

static SDL_Point cannon_mesh[5] = {
    {-20, -10},
    {-20,  10},
    { 20,  10},
    { 20, -10},
    {-20, -10},
};

cannon::cannon(vec2 position, real_t angle, const bullet *bt, real_t damping, U8 r, U8 g, U8 b) :
  _transform{angle, position},
  _bullet{bt},
  _angular_velocity{0.0},
  _damping{damping},
  _r{r},
  _g{g},
  _b{b}
{}

void cannon::tick()
{
  if(std::fabs(_angular_velocity) > 0.0) {
    _angular_velocity *= _damping;

    // stabalise to 0 if below a small threshold.
    if(std::fabs(_angular_velocity) <= 5.0_deg_p_s)
      _angular_velocity = 0.0;
    
    _transform.rotate(_angular_velocity * cfg::physics::tick_delta);
  }
}

void cannon::draw(SDL_Renderer* renderer)
{
  static SDL_Point points[5];

  // transform the local points to world space
  vec2 v;
  for(int i = 0; i < 5; ++i) {
    v.x = cannon_mesh[i].x;
    v.y = cannon_mesh[i].y;

    v = _transform.transform_point(v);

    points[i].x = v.x;
    points[i].y = v.y;
  }

  SDL_SetRenderDrawColor(renderer, _r, _g, _b, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawLines(renderer, points, 5);
}

void cannon::fire(std::list<particle>& particles) const
{
  assert(_bullet != nullptr);

  particles.emplace_back(
    _transform.get_translation(),
    _transform.transform_direction({_bullet->_speed, 0.0}),
    vec2{0.0, _bullet->_gravity},
    _bullet->_radius,
    _bullet->_inverse_mass,
    _bullet->_damping,
    _bullet->_r,
    _bullet->_g,
    _bullet->_b
  );
}

void cannon::set_bullet(const bullet *b)
{
  _bullet = b;
}

void cannon::set_angular_velocity(real_t angular_velocity)
{
  _angular_velocity = angular_velocity;
}

