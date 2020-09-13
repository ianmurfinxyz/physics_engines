#include "ticker.h"

ticker::ticker(real_t frequency, I32 frame_tick_limit, std::chrono::nanoseconds origin, tick_mode mode)
{
  _next_tick = origin;
  _frequency = frequency;
  _frame_tick_limit = frame_tick_limit;
  _mode = mode;

  _count = 0;
  _frame = -1;
  _frame_tick_count = 0;
  _is_signalled = false;

  _period = std::chrono::nanoseconds {static_cast<I64>(1.0e9 / frequency)};
}

bool ticker::next_tick(const std::chrono::nanoseconds& game_time, I64 frame)
{
  if(_mode == tick_mode::timed)
    return do_timed_tick(game_time, frame);

  else
    return do_manual_tick();
}

bool ticker::signal_tick() {
  _is_signalled = (_mode == tick_mode::manual) ? true : false;
  return _is_signalled;
}

void ticker::enable_manual_ticking() 
{
  _mode = tick_mode::manual;
  _is_signalled = false;
}

void ticker::enable_timed_ticking(const std::chrono::nanoseconds& game_time)
{
  _next_tick = game_time + _period;
  _frame = -1;
}

bool ticker::do_timed_tick(const std::chrono::nanoseconds& game_time, I64 frame)
{
  if(_frame != frame) {
    _frame = frame;
    _frame_tick_count = 0;
  }

  if(_next_tick < game_time && _frame_tick_count < _frame_tick_limit) {
    ++_count;
    ++_frame_tick_count;
    _next_tick += _period;
    return true;
  }

  return false;
}

bool ticker::do_manual_tick()
{
  ++_count;
  _is_signalled = false; 
  return true;
}

