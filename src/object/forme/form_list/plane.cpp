#include "plane.hpp"

plane::plane() : normal(vec3(0,1,0)), center(0), dir(vec3(0,0,1)) {};
plane::plane(vec3 n) : normal(unit_vector(n)), center(0), dir(vec3(0,0,1)) {};
plane::plane(vec3 n, vec3 p) : normal(unit_vector(n)), center(p), dir(vec3(0,0,1)) {};
plane::plane(vec3 n, vec3 p, vec3 d) : normal(unit_vector(n)), center(p), dir(unit_vector(d)) {};

double plane::distance(vec3 pos) const {
    return dot(normal,pos-center);
}


void plane::coord_from_impact(vec3 pos, double &u, double &v) const {
    vec3 p = pos-center;
    u = dot(p,dir);
    v = dot(p,cross(normal,dir));
}