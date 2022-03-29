#include "sphere.hpp"

sphere::sphere() {};
sphere::sphere(vec3 cen, double r) : center(cen), radius(r) {}

double sphere::distance(vec3 pos) const {
    vec3 v = pos-center;
    double d = v.norm();
    return d-radius;
}

//pas encore implémenté
void sphere::coord_from_impact(vec3 pos, double &u, double &v) const {
    vec3 p = pos-center;
    u = 0;
    v = 0;
}