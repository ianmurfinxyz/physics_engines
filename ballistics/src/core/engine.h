#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <SDL2/SDL.h>
#include <chrono>
#include "../system/typedefs.h"
#include "../system/types.h"
#include "../system/high_resolution_clock.h"
#include "ticker.h"
#include "config.h"
#include "../world/world.h"

class engine
{
public:
  engine();

  void init();
  void shutdown();
  void run();

private:
  _FORCE_INLINE_ void gameloop();  

private:
  std::chrono::nanoseconds _real_time;
  high_resolution_clock _game_clock;
  ticker _physics_ticker;
  ticker _render_ticker;

  SDL_Window *_window;
  SDL_Renderer *_renderer;

  world *_world;

  I64 _frame;
  bool _is_running;
};

#endif
