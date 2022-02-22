#ifndef TEXTURE_MIROR_C
#define TEXTURE_MIROR_C

#include "miror.hpp"

miror::miror() : c(color(1)) {reflexion = true; p = 0;};

color miror::couleur(hit_record h) const {
    return this->c;
};

vec3 miror::rayon(hit_record h) const {
    double b = dot(h.i,h.n);
    vec3 r = h.i-2*b*h.n;
    return unit_vector(r);
};


#endif