#ifndef TEXTURE_LAMBERTIAN_C
#define TEXTURE_LAMBERTIAN_C

#include "lambertian.hpp"

lambertian::lambertian() : c(color(0.5)) {};

color lambertian::couleur(hit_record h) const {
    return this->c;
};
vec3 lambertian::rayon(hit_record h) const {
    return vec3(0);
};


#endif