#ifndef _BASIS2_H_
#define _BASIS2_H_

#include "vec2.h"

class basis2
{
public:
  enum axis {x, y};

  basis2();
  basis2(vec2 x_axis, vec2 y_axis);
  basis2(real_t xx, real_t xy, real_t yx, real_t yy);
  basis2(real_t angle);

  void rotate(real_t angle);
  
  vec2 transform(const vec2& v) const;

  basis2 operator*(const basis2& b) const;
  void operator*=(const basis2& b);

  void set_identity();

  real_t get_angle() const;

private:
  real_t e[2][2];
};

#endif
