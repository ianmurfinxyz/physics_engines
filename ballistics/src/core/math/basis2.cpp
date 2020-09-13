#include <cmath>
#include "basis2.h"

basis2::basis2() : 
  e{{1, 0},{0, 1}}
{}

basis2::basis2(vec2 x_axis, vec2 y_axis) : 
  e{{x_axis.x, x_axis.y},{y_axis.x, y_axis.y}}
{}

basis2::basis2(real_t xx, real_t xy, real_t yx, real_t yy) :
  e{{xx, xy},{yx, yy}}
{}

basis2::basis2(real_t angle) : 
  e{{std::cos(angle), std::sin(angle)}, {-(std::sin(angle)), std::cos(angle)}}
{}

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
  e[axis::x][0] = 1;
  e[axis::x][1] = 0;
  e[axis::y][0] = 0;
  e[axis::y][1] = 1;
}

real_t basis2::get_angle() const
{
  return std::acos(e[axis::x][0]);
}

basis2 basis2::operator*(const basis2& b) const
{
  return basis2{
    {(e[0][0]*b.e[0][0] + e[1][0]*b.e[0][1]), (e[0][1]*b.e[0][0] + e[1][1]*b.e[0][1])},
    {(e[0][0]*b.e[1][0] + e[1][0]*b.e[1][1]), (e[0][1]*b.e[1][0] + e[1][1]*b.e[1][1])}
  };
}

void basis2::operator*=(const basis2& b)
{
  *this = basis2{
    {(e[0][0]*b.e[0][0] + e[1][0]*b.e[0][1]), (e[0][1]*b.e[0][0] + e[1][1]*b.e[0][1])},
    {(e[0][0]*b.e[1][0] + e[1][0]*b.e[1][1]), (e[0][1]*b.e[1][0] + e[1][1]*b.e[1][1])}
  };
}
