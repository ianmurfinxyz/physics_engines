#include <SDL2/SDL.h>
#include <iostream>
#include "engine.h"

using namespace std;

engine::engine() : _real_time{}, 
                   _game_clock{}, 
                   _physics_ticker{cfg::physics::tick_frequency, cfg::physics::tick_limit},
                   _render_ticker{cfg::renderer::tick_frequency, 1},
                   _world{nullptr},
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

  _world = new world{};
}

void engine::shutdown()
{
  delete _world;
  _world = nullptr;

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
    _world->on_event(event);
  }

  while(_physics_ticker.next_tick(_game_clock.get_now(), _frame)) {
    //cout << "physics tick: " << static_cast<double>(_game_clock.get_now().count()) / 1.0e9  << "s" << endl;
    _world->tick();
  }

  while(_render_ticker.next_tick(_game_clock.get_now(), _frame)) {
    _world->draw(_renderer);
  }

}
