#pragma once

#include "damier.hpp"

damier::damier() : couleur1(color(1)), couleur2(color(0.01)) {};
damier::damier(color c1, color c2) : couleur1(c1), couleur2(c2) {};

vec3 damier::rayon(hit_record h) const {
    vec3 ray = unit_vector(h.normal + random_in_unit_sphere());
    return ray;
};

color damier::reflexion(hit_record in, color c, vec3 out) const {
    color res;
    vec3 d1(1,0,0); vec3 d2(0,0,1);
    double a1 = dot(d1,in.pos); a1 = a1 - floor(a1);
    double a2 = dot(d2,in.pos); a2 = a2 - floor(a2);
    if ((a1 < 0.5) ^ (a2 < 0.5)) res = couleur1;
    else res = couleur2;
    return res*c*dot(in.normal,in.wi);
}

color damier::emittance(hit_record in) const {
    return color(0);
}
