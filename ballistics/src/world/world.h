#ifndef _WORLD_H_
#define _WORLD_H_

#include <SDL2/SDL.h>
#include <list>
#include "particle.h"
#include "cannon.h"

class world
{
public:
  world();

  void on_event(const SDL_Event& event);

  // call within the physics update for now
  void tick();

  void draw(SDL_Renderer *renderer);

private:
  std::list<particle> _particles;
  cannon _harry; // do you feel lucky...punk!
};

#endif
