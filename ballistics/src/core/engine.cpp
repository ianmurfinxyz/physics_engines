#include <SDL2/SDL.h>
#include <iostream>
#include "engine.h"

using namespace std;

engine::engine() : _real_time{}, 
                   _game_clock{}, 
                   _physics_ticker{cfg::physics_frequency_hz, cfg::physics_tick_limit},
                   _render_ticker{cfg::render_frequency_hz, 1},
                   _frame{-1},
                   _is_running{true}
{}

void engine::init()
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if(SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &_window, &_renderer)){
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create window and renderer: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

}

void engine::shutdown()
{
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

void engine::run()
{
  while(_is_running)
    gameloop();
}

void engine::gameloop()
{
  static auto last_clock_sample = chrono::steady_clock::now();

  ++_frame;

  auto clock_sample = chrono::steady_clock::now();
  auto real_delta = chrono::duration_cast<chrono::nanoseconds>(clock_sample - last_clock_sample);
  last_clock_sample = clock_sample;
  _real_time += real_delta;

  _game_clock.update(real_delta);

  SDL_Event event;
  while(SDL_PollEvent(&event) != 0) {
    switch(event.type) {
      case SDL_QUIT:
        _is_running = false;
        break;
    }
  }

  while(_physics_ticker.next_tick(_game_clock.get_now(), _frame)) {

    // tick physics engine...
    
  }

  while(_render_ticker.next_tick(_game_clock.get_now(), _frame)) {

    // tick renderer...

  }

}
