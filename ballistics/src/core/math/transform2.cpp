
#include "transform2.h"

transform2::transform2(const basis2& b, vec2 translation) :
  _basis{b},
  _translation{translation}
{}

transform2::transform2(real_t angle, vec2 translation) :
  _basis{angle},
  _translation{translation}
{}

transform2::transform2(vec2 x_axis, vec2 y_axis, vec2 translation) :
  _basis{x_axis, y_axis},
  _translation{translation}
{}

void transform2::translate(vec2 translation)
{
  _translation += translation;
}

void transform2::rotate(real_t angle)
{
  _basis.rotate(angle);
}

vec2 transform2::transform_point(vec2 v) const
{
  vec2 r = _basis.transform(v);
  r += _translation;
  return r;
}

vec2 transform2::transform_direction(vec2 v) const
{
  return _basis.transform(v);
}

real_t transform2::get_angle() const
{
  return _basis.get_angle();
}

