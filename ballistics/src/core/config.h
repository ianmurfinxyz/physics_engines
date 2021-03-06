
#include "../system/types.h"
#include "math/units.h"
#include "math/math_defs.h"

namespace cfg
{
namespace physics
{
const real_t tick_frequency = 30.0_hz;
const real_t tick_delta = (1.0 / tick_frequency); 
const I32 tick_limit = 5;
const real_t linear_damping = 0.999;
const real_t angular_damping = 0.999;
}
namespace renderer
{
const real_t tick_frequency = 60.0_hz;
}
namespace world
{
const I32 screen_width = 800;
const I32 screen_height = 600;
}
}
