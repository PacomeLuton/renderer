#include "plane.hpp"

plane::plane() : normal(vec3(0,1,0)), center(0) {};
plane::plane(vec3 n) : normal(unit_vector(n)), center(0) {};
plane::plane(vec3 n, vec3 p) : normal(unit_vector(n)), center(p) {};

double plane::distance(vec3 pos) const {
    return dot(normal,pos-center);
}
