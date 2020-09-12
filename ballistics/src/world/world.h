#ifndef _WORLD_H_
#define _WORLD_H_

#include <SDL2/SDL.h>
#include <list>

class world
{
public:
  void init();
  void on_event(const SDL_Event& event);
  void tick();
  void draw();

private:
  std::list particles;
};

#endif
