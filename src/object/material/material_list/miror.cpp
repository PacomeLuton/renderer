#include "miror.hpp"

color miror::emittance(hit_record in) const {
    return color(0);
}

vec3 miror::rayon(hit_record in) const {
    double b = dot(in.wi,in.normal); 
    vec3 r = in.wi - 2*b*in.normal;
    return unit_vector(r); //on normalise le rayon qui sort
};