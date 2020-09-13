#ifndef _TICK_CLOCK_H_
#define _TICK_CLOCK_H_

#include <chrono>
#include "../system/types.h"
#include "math/math_defs.h"

//
// Manages the ticking of a subsystem.
//
class ticker
{
public:
  enum class tick_mode { timed, manual };

  explicit ticker(real_t frequency, 
                  I32 frame_tick_limit, 
                  std::chrono::nanoseconds origin = std::chrono::nanoseconds {0},
                  tick_mode mode = tick_mode::timed);

  //
  // Attempts to perform a tick. Success depends on mode, frame and game time.
  //
  // @game_time - current time on the game clock.
  // @frame - number of the frame in which this tick is requested.
  //
  // return - true on tick performed.
  //
  bool next_tick(const std::chrono::nanoseconds& game_time, I64 frame);

  //
  // Signals a manual tick, returns true if successful. Only fails if mode == timed. The tick is
  // only signaled, call 'next_tick' to perform the tick.
  //
  bool signal_tick();

  //
  // Enables manual ticking; must then call 'signal_tick' for each tick.
  //
  void enable_manual_ticking();

  //
  // Switches to timed ticking.
  //
  // @param game_time - the new origin of the tick timeline.
  //
  void enable_timed_ticking(const std::chrono::nanoseconds& game_time);

private:
  bool do_timed_tick(const std::chrono::nanoseconds& game_time, I64 frame);
  bool do_manual_tick();

private:
  std::chrono::nanoseconds _next_tick;    // game time of next tick
  std::chrono::nanoseconds _period;       // period of each tick
  I64 _count;                             // total times ticked
  I64 _frame;                             // frame of last tick
  real_t _frequency;                      // rate of ticking
  I32 _frame_tick_count;                  // ticks performed this frame
  I32 _frame_tick_limit;                  // max ticks performed each frame
  tick_mode _mode;
  bool _is_signalled;                      // used for manual mode.
};

#endif
