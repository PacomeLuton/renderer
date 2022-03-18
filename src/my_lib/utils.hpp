#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <limits>

// Constants

const double infinity = 1e9;
const double pi = 3.1415926535897932385;

// Utility Functions

double min (double a, double b);
double closet_nul (double a, double b);
double max (double a, double b);
double clamp(double x, double min, double max);
double smin( double a, double b, double k );

double random_double();
double random_double(double min, double max);

#endif