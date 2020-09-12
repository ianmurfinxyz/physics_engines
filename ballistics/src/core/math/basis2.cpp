#include "basis2.h"

basis2::basis2() 
{
  e = {
    {1, 0},
    {0, 1}
  };
}

basis2::basis2(vec2 x_axis, vec2 y_axis)
{
  e[axis::x][0] = x_axis.x;
  e[axis::x][1] = x_axis.y;
  e[axis::y][0] = y_axis.x;
  e[axis::y][1] = y_axis.y;
}

basis2::basis2(real_t xx, real_t xy, real_t yx, real_t yy) :
  e[axis::x][0]{xx}, 
  e[axis::x][1]{xy}, 
  e[axis::y][0]{yx}, 
  e[axis::y][1]{yy}
{}

basis2::basis2(real_t angle)
{
  e = {
    {std::cos(angle), std::sin(angle)},
    {-(std::sin(angle)), std::cos(angle)}
  };
}

void basis2::rotate(real_t angle)
{
  *this *= basis2(angle);
}
  
vec2 basis2::transform(const vec2& v) const
{
  return vec2{
    (e[axis::x][0] * v.x) + (e[axis::y][0] * v.y),
    (e[axis::x][1] * v.x) + (e[axis::y][1] * v.y)
  };
}

void basis2::set_identity()
{
  e = {
    {1, 0},
    {0, 1}
  };
}

void basis2::get_angle() const
{
  return std::acos(e[axis::x][0]);
}

#endif
