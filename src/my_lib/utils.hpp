#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <limits>

// Constants

const double infinity = 1e9;
const double pi = 3.1415926535897932385;

// Utility Functions

inline double min (double a, double b);
inline double closet_nul (double a, double b);
inline double max (double a, double b);
inline double clamp(double x, double min, double max);
double smin( double a, double b, double k );

inline double random_double();
inline double random_double(double min, double max);

#endif