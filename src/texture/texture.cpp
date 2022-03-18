#ifndef TEXTURE_C
#define TEXTURE_C

#include "texture.hpp"

color material::emittance(hit_record in) const {
    return color(0);
}

color material::reflexion(hit_record in, color c, vec3 out) const {
    return color(0);
}

vec3 material::rayon(hit_record h) const {
    return vec3(0); 
    //par convention, si le rayon est nul, on dit qu'il y a pas de rayon reflechi
}

#endif