#ifndef TEXTURE_UNIFORM_C
#define TEXTURE_UNIFORM_C

#include "uniform.hpp"

uniform_texture::uniform_texture() : c(color(0.5)) {};
uniform_texture::uniform_texture(color col) : c(col) {};

color uniform_texture::couleur(hit_record h) const{
    return c;
};
vec3 uniform_texture::rayon(hit_record h) const{
    return vec3(0);
};


#endif