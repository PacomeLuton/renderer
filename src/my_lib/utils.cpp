#include "utils.hpp"

double min (double a, double b) { 
    return !(b<a)?a:b; 
}

double closet_nul (double a, double b) { 
    return !(abs(b)<abs(a))?a:b; 
}

double max (double a, double b) { 
    return (b<a)?a:b; 
}

double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

double smin( double a, double b, double k ){
    double h = max( k-abs(a-b), 0.0 )/k;
    return min( a, b ) - h*h*k*(1.0/4.0);
}

double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    // Returns a random real in [0,1).
    double r = random_double();
    return (min + r*(max-min));
}