#ifndef INFINITE_CYLINDER_C
#define INFINITE_CYLINDER_C

#include "infinite_cylinder.hpp"

infinite_cylinder::infinite_cylinder() {};
infinite_cylinder::infinite_cylinder(vec3 cen, double r) : center(cen), radius(r), axe(unit_vector(vec3(1))) {};
infinite_cylinder::infinite_cylinder(vec3 cen, double r, vec3 a) : center(cen), radius(r), axe(unit_vector(a)) {};


double infinite_cylinder::distance(vec3 pos) const {
    vec3 p = pos-center;
    double a = dot(p,axe);
    return length(p-a*axe)-radius;
}

#endif