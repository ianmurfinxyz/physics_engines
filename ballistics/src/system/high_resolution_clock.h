#ifndef _HIGH_RESOLUTION_CLOCK_H_
#define _HIGH_RESOLUTION_CLOCK_H_

#include <chrono>
#include "types.h"

class high_resolution_clock
{
public:
  high_resolution_clock() : _now{0}, _time_scale{1.f}, _is_paused{false} {}

  const std::chrono::nanoseconds& update(const std::chrono::nanoseconds& delta);

  const std::chrono::nanoseconds& get_now() const {return _now;}

  void set_scale(F32 scale) {_time_scale = scale;}
  void pause() {_is_paused = true;}

  F32 get_scale() const {return _time_scale;}
  bool is_paused() const {return _is_paused;}

private:
  std::chrono::nanoseconds _now; 
  F32 _time_scale;
  bool _is_paused;
};

#endif
