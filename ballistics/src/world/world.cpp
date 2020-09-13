#include "world.h"
#include "bullet.h"
#include "../core/config.h"

const static real_t harry_angular_velocity {10.0};

static const bullet artillery = {
  50.0_m_p_s,
  1.0 / 200.0_kg,
  20.0_m_p_s2,
  0.99,
  40,
  40,
  40
};

static const bullet fireball = {
  10.0_m_p_s,
  1.0 / 1.0_kg,
  -0.6_m_p_s2,
  0.9,
  255,
  68,
  0
};

world::world() : _harry{{50.0, cfg::world::screen_height - 50.0}, 0.0, &fireball, 0.5, 0, 0, 0)}
{}

void world::on_event(const SDL_Event& event)
{
  switch(event.type)
  {
  case SDL_KEYDOWN:
    if(event.key.keysym.sym == SDLK_DOWN)
      _harry.set_angular_velocity(harry_angular_velocity);

    else if(event.key.keysym.sym == SDLK_UP)
      _harry.set_angular_velocity(-harry_angular_velocity);

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
  SDL_RenderFillRect(renderer, field);

  _harry.draw();

  for(auto& p : _particles)
    p.draw();

  SDL_RenderPresent(renderer);
}
