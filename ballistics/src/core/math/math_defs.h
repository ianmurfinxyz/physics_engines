#ifndef _MATH_DEFS_H_
#define _MATH_DEFS_H_

#include "../../system/types.h"

// 
// Sets the data type for the field of the real vector space ℝⁿ 
// used throughtout the math lib.
//
#ifdef DOUBLE_REAL_T
using real_t = F64;
#else
using real_t = F32;
#endif

#endif
