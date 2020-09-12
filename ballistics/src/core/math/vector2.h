#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <cmath>
#include "math_defs.h"

//
// An element of the real vector space ℝ².
//
struct Vector2
{
  real_t x = 0;
  real_t y = 0;

  Vector2() {}
  Vector2(real_t x, real_t y) : x{x}, y{y} {}

  Vector2 operator+(const Vector2& v) const;
  void operator+=(const Vector2& v);
  Vector2 operator-(const Vector2& v) const;
  void operator-=(const Vector2& v);

  // componentwise multiplication (hadamard product)
  Vector2 operator*(const Vector2& v) const;
  void operator*=(const Vector2& v);

  Vector2 operator*(const real_t scale) const;
  void operator*=(const real_t scale);

  real_t dot(const Vector2& v) const;
  real_t cross(const Vector2& v) const;

  Vector2 normalized() const;
  void normalize();

  real_t length() const;
  real_t length_squared() const;
};

Vector2 Vector2::operator+(const Vector2& v) const
{
  return Vector2{x + v.x, y + v.y}; 
}

void Vector2::operator+=(const Vector2& v)
{
  x += v.x;
  y += v.y;
}

Vector2 Vector2::operator-(const Vector2& v) const
{
  Vector2{x - v.x, y - v.y};
}

void Vector2::operator-=(const Vector2& v)
{
  x -= v.x;
  y -= v.y;
}

Vector2 Vector2::operator*(const Vector2& v) const
{
  Vector2{x * v.x, y * v.y};
}

void Vector2::operator*=(const Vector2& v)
{
  x *= v.x;
  y *= v.y;
}

Vector2 Vector2::operator*(const real_t scale) const
{
  Vector2{x * scale, y * scale);
}

void Vector2::operator*=(const real_t scale)
{
  x *= scale;
  y *= scale;
}

real_t Vector2::dot(const Vector2& v) const
{
  return (x * v.x) + (y * v.y);
}

real_t Vector2::cross(const Vector2& v) const
{
  return (x * v.y) - (y * v.x);
}

Vector2 Vector2::normalized() const
{
  Vector2 v = *this;
  v.normalize();
  return v;
}

void Vector2::normalize()
{
  real_t l = (x * x) + (y * y);
  if(l){
    l = std::sqrt(l);
    x /= l;
    y /= l;
  }
}

real_t Vector2::length() const
{
  // may be slower as performs bounds checking.
  // https://www.codeproject.com/Questions/1209091/Cplusplus-hypot-slower-than-standard-function-and
  // will want to test.
  return std::hypot(x, y);  
}

real_t Vector2::length_squared() const
{
  // faster or slower than pow(x, 2) + pow(y, 2), expect slower as no function calls. test it!
  return (x * x) + (y * y);
}

#endif
