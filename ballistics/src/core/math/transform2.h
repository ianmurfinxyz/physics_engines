#ifndef _TRANSFORM2_H_
#define _TRANSFORM2_H_

#include "basis2.h"
#include "vec2.h"

class transform2
{
public:
  transform2(){}
  transform2(const basis2& b, vec2 translation);
  transform2(real_t angle, vec2 translation);
  transform2(vec2 x_axis, vec2 y_axis, vec2 translation);

  void translate(vec2 translation);
  void rotate(real_t angle);

  vec2 transform_point(vec2 v) const;
  vec2 transform_direction(vec2 v) const;

  real_t get_angle() const;
  const basis2& get_basis() const {return basis;}
  vec2 get_translation() const {return translation;}

private:
  basis2 _basis;
  vec2 _translation;
};


#endif
