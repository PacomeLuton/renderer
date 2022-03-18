#pragma once

#include "square.hpp"

square::square() {};
square::square(vec3 c, vec3 d) : center(c), dim(d) {};

double square::distance(vec3 pos) const {
    vec3 v = pos-center;
    vec3 q = abs(v) - dim;
    double d = length(max(q,0.0)) + min(max(q.x(),max(q.y(),q.z())),0.0);
    return d;
}