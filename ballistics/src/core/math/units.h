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

//
// velocities
//
constexpr long double operator"" _px_p_s(long double px_p_s){return px_p_s;}
constexpr long double operator"" _m_p_s(long double m_p_s){return m_p_s;}
constexpr long double operator"" _km_p_s(long double km_p_s){return km_p_s * 1.0e3;}

//
// accelerations
//
constexpr long double operator"" _px_p_s2(long double px_p_s2){return px_p_s2;}
constexpr long double operator"" _m_p_s2(long double m_p_s2){return m_p_s2;}
constexpr long double operator"" _km_p_s2(long double km_p_s2){return km_p_s2 * 1.0e3;}

//
// mass
//
// note - kg is the base unit.
//
constexpr long double operator"" _g(long double g){return g * 1.0e3;}
constexpr long double operator"" _kg(long double kg){return kg;}


#endif
