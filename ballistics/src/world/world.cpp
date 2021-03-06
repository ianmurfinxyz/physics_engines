#include "world.h"
#include "bullet.h"
#include "../core/config.h"

const static real_t harry_swivel_speed {60.0_deg_p_s};
const static real_t harry_swivel_damping {0.8};
const static real_t particle_lifetime {10.0_s};

static const bullet artillery = {
  400.0_m_p_s,
  1.0 / 200.0_kg,
  120.0_m_p_s2,
  0.99,
  5.0_px,
  40,
  40,
  40
};

static const bullet fireball = {
  500.0_m_p_s,
  1.0 / 1.0_kg,
  -100.0_m_p_s2,
  0.95,
  3.0_px,
  255,
  68,
  0
};

world::world() : _harry{{50.0, cfg::world::screen_height - 50.0}, 0.0, &fireball, harry_swivel_damping, 0, 0, 0}
{}

void world::on_event(const SDL_Event& event)
{
  switch(event.type)
  {
  case SDL_KEYDOWN:
    if(event.key.keysym.sym == SDLK_DOWN)
      _harry.set_angular_velocity(harry_swivel_speed);

    else if(event.key.keysym.sym == SDLK_UP)
      _harry.set_angular_velocity(-harry_swivel_speed);

    else if(event.key.keysym.sym == SDLK_SPACE && !event.key.repeat)
      _harry.fire(_particles);

    else if(event.key.keysym.sym == SDLK_a && !event.key.repeat)
      _harry.set_bullet(&artillery);

    else if(event.key.keysym.sym == SDLK_f && !event.key.repeat)
      _harry.set_bullet(&fireball);
  }
}

void world::tick()
{
  _harry.tick();

  for(auto& p : _particles)
    p.tick();

  for(auto iter = _particles.begin(); iter != _particles.end();){
    if((*iter).get_age() > particle_lifetime)
      iter = _particles.erase(iter);
    else
      ++iter;
  }
}

void world::draw(SDL_Renderer *renderer)
{
  // draw sky
  SDL_SetRenderDrawColor(renderer, 196, 255, 234, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  // draw field
  SDL_Rect field;
  field.x = 0;
  field.y = cfg::world::screen_height - 40;
  field.w = cfg::world::screen_width;
  field.h = 40;
  SDL_SetRenderDrawColor(renderer, 123, 181, 110, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(renderer, &field);

  _harry.draw(renderer);

  for(auto& p : _particles)
    p.draw(renderer);

  SDL_RenderPresent(renderer);
}
