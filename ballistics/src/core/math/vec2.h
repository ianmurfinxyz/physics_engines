#ifndef _VEC2_H_
#define _VEC2_H_

#include <cmath>
#include "math_defs.h"

//
// An element of the real vector space ℝ².
//
struct vec2
{
  real_t x = 0;
  real_t y = 0;

  vec2() {}
  vec2(real_t x, real_t y) : x{x}, y{y} {}

  vec2 operator+(const vec2& v) const;
  void operator+=(const vec2& v);
  vec2 operator-(const vec2& v) const;
  void operator-=(const vec2& v);

  // componentwise multiplication (hadamard product)
  vec2 operator*(const vec2& v) const;
  void operator*=(const vec2& v);

  vec2 operator*(const real_t scale) const;
  void operator*=(const real_t scale);

  real_t dot(const vec2& v) const;
  real_t cross(const vec2& v) const;

  vec2 normalized() const;
  void normalize();

  real_t length() const;
  real_t length_squared() const;
};

vec2 vec2::operator+(const vec2& v) const
{
  return vec2{x + v.x, y + v.y}; 
}

void vec2::operator+=(const vec2& v)
{
  x += v.x;
  y += v.y;
}

vec2 vec2::operator-(const vec2& v) const
{
  vec2{x - v.x, y - v.y};
}

void vec2::operator-=(const vec2& v)
{
  x -= v.x;
  y -= v.y;
}

vec2 vec2::operator*(const vec2& v) const
{
  vec2{x * v.x, y * v.y};
}

void vec2::operator*=(const vec2& v)
{
  x *= v.x;
  y *= v.y;
}

vec2 vec2::operator*(const real_t scale) const
{
  vec2{x * scale, y * scale);
}

void vec2::operator*=(const real_t scale)
{
  x *= scale;
  y *= scale;
}

real_t vec2::dot(const vec2& v) const
{
  return (x * v.x) + (y * v.y);
}

real_t vec2::cross(const vec2& v) const
{
  return (x * v.y) - (y * v.x);
}

vec2 vec2::normalized() const
{
  vec2 v = *this;
  v.normalize();
  return v;
}

void vec2::normalize()
{
  real_t l = (x * x) + (y * y);
  if(l){
    l = std::sqrt(l);
    x /= l;
    y /= l;
  }
}

real_t vec2::length() const
{
  // may be slower as performs bounds checking.
  // https://www.codeproject.com/Questions/1209091/Cplusplus-hypot-slower-than-standard-function-and
  // will want to test.
  return std::hypot(x, y);  
}

real_t vec2::length_squared() const
{
  // faster or slower than pow(x, 2) + pow(y, 2), expect slower as no function calls. test it!
  return (x * x) + (y * y);
}

#endif
