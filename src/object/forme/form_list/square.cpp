#include "square.hpp"

square::square() {};
square::square(vec3 c, vec3 d) : center(c), dim(d) {};
square::square(vec3 c, vec3 d, mat3 r) : center(c), dim(d), rot(r) {};

double square::distance(vec3 pos) const {
    vec3 v = rot*(pos-center);
    vec3 q = abs(v) - dim;
    double d = length(max(q,0.0)) + min(max(q.x(),max(q.y(),q.z())),0.0);
    return d;
}

//pas encore implémenté
void square::coord_from_impact(vec3 pos, double &u, double &v) const {
    vec3 p = pos-center;
    u = 0;
    v = 0;
}