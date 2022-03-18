#ifndef TEXTURE_MIROR_C
#define TEXTURE_MIROR_C

#include "miror.hpp"

miror::miror() : couleur(color(1)) {};
miror::miror(color col) : couleur(col) {};

color miror::reflexion(hit_record in, color c, vec3 out) const {
    return this->couleur*c;
};

color miror::emittance(hit_record in) const {
    return color(0);
}

vec3 miror::rayon(hit_record in) const {
    double b = dot(in.wi,in.normal); 
    vec3 r = in.wi - 2*b*in.normal;
    return unit_vector(r); //on normalise le rayon qui sort
};


#endif