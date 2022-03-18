#ifndef LAMBERTIAN_C
#define LAMBERTIAN_C

#include "lambertian.hpp"

lambertian::lambertian() : couleur(color(0.5)) {};
lambertian::lambertian(color col) : couleur(col) {};

vec3 lambertian::rayon(hit_record h) const {
    vec3 ray = unit_vector(h.normal + random_in_unit_sphere());
    return ray;
};

color lambertian::reflexion(hit_record in, color c, vec3 out) const {
    return this->couleur * c * dot(in.normal, in.wi);
}

color lambertian::emittance(hit_record in) const {
    return color(0);
}

#endif