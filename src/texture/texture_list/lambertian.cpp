#ifndef TEXTURE_LAMBERTIAN_C
#define TEXTURE_LAMBERTIAN_C

#include "lambertian.hpp"

lambertian::lambertian() : c(color(0.5)) {reflexion = true; p = 0.7;};
lambertian::lambertian(color col) : c(col) {reflexion = true; p = 0.7;};


color lambertian::couleur(hit_record h) const {
    return this->c;
};

vec3 lambertian::rayon(hit_record h) const {
    vec3 ray = unit_vector(h.n + vec3::random_unit());
    return ray;
};


#endif