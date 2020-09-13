#ifndef _VEC2_H_
#define _VEC2_H_

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

  vec2 operator*(real_t scale) const;
  void operator*=(real_t scale);

  real_t dot(const vec2& v) const;
  real_t cross(const vec2& v) const;

  vec2 normalized() const;
  void normalize();

  real_t length() const;
  real_t length_squared() const;
};

#endif
