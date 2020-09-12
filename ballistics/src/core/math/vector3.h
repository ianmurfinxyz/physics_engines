#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <cmath>
#include "math_defs.h"

//
// An element of the real vector space ℝ³.
//
struct Vector3
{
  real_t x = 0;
  real_t y = 0;
  real_t z = 0;

  Vector3() {}
  Vector3(real_t x, real_t y, real_t z) : x{x}, y{y}, z{z} {}

  Vector3 operator+(const Vector3& v) const;
  void operator+=(const Vector3& v);
  Vector3 operator-(const Vector3& v) const;
  void operator-=(const Vector3& v);

  // componentwise multiplication (hadamard product)
  Vector3 operator*(const Vector3& v) const;
  void operator*=(const Vector3& v);

  Vector3 operator*(const real_t scale) const;
  void operator*=(const real_t scale);

  real_t dot(const Vector3& v) const;
  Vector3 cross(const Vector3& v) const;

  Vector3 normalized() const;
  void normalize();

  real_t length() const;
  real_t length_squared() const;
};

Vector3 Vector3::operator+(const Vector3& v) const
{
  return Vector3{x + v.x, y + v.y, z + v.z};
}

void Vector3::operator+=(const Vector3& v)
{
  x += v.x;
  y += v.y;
  z += v.z;
}

Vector3 Vector3::operator-(const Vector3& v) const
{
  return Vector3{x - v.x, y - v.y, z - v.z};
}

void Vector3::operator-=(const Vector3& v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
}

Vector3 Vector3::operator*(const Vector3& v) const
{
  return Vector3{x * v.x, y * v.y, z * v.z};
}

void Vector3::operator*=(const Vector3& v)
{
  x *= v.x;
  y *= v.y;
  z *= v.z;
}

Vector3 Vector3::operator*(const real_t scale) const
{
  return Vector3{x * scale, y * scale, z * scale};
}

void Vector3::operator*=(const real_t scale)
{
  x *= scale;
  y *= scale;
  z *= scale;
}

real_t Vector3::dot(const Vector3& v) const
{
  return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector3 Vector3::cross(const Vector3& v) const
{
  return Vector3{(y * v.z) - (z * v.y), -((x * v.z) - (z * v.x)), (x * v.y) - (y * v.x)};
}

Vector3 Vector3::normalized() const
{
  Vector3 v = *this;
  v.normalize();
  return v;
}

void Vector3::normalize()
{
  real_t l = (x * x) + (y * y) + (z * z);
  if(l){
    l = std::sqrt(l);
    x /= l;
    y /= l;
    z /= l;
  }
}

real_t Vector3::length() const
{
  return std::hypot(x, y, z);
}

real_t Vector3::length_squared() const
{
  return (x * x) + (y * y) + (z * z);
}

#endif
