#include "high_resolution_clock.h"

using namespace std;

const chrono::nanoseconds& high_resolution_clock::update(const chrono::nanoseconds& delta)
{
  if(!_is_paused)
    _now += chrono::duration_cast<chrono::nanoseconds>(delta * _time_scale);

  return _now;
}

