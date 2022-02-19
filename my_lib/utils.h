#ifndef UTILS_H
#define UTILS_H

#include <cmath>
// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline const double min (double a, double b) { 
    return !(b<a)?a:b; 
}

inline const double closet_nul (double a, double b) { 
    return !(abs(b)<abs(a))?a:b; 
}

inline const double max (double a, double b) { 
    return (b<a)?a:b; 
}
inline const double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}
double smin( double a, double b, double k ){
    double h = max( k-abs(a-b), 0.0 )/k;
    return min( a, b ) - h*h*k*(1.0/4.0);
}


inline double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

/*
    type abs (type x)
    type sign (type x)
    type floor (type x)
    type ceil (type x)
    type trunc (type x)
    type fract (type x)
    type mod (type x, double y)
    type modf (type x, out type i)
    type min (type x, type y)
    type max (type x, type y)
    type clamp (type x, type minV, type maxV)
    type mix (type x, type y, type a)
    type step (type edge, type x)
    type smoothstep (type a, type b, type x)
*/

#endif