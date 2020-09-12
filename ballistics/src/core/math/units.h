#ifndef _UNITS_H_
#define _UNITS_H_

//
// Linear Spatial Units
//
// note - px == m which is the base unit of world space.
//
constexpr long double operator"" _px(long double px){return px;}
constexpr long double operator"" _m(long double m){return m;}
constexpr long double operator"" _km(long double km){return km * 1.0e3;}

//
// Frequencies
//
constexpr long double operator"" _hz(long double hz){return hz;}

#endif
