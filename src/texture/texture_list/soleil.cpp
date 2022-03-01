#ifndef TEXTURE_SOLEIL_C
#define TEXTURE_SOLEIL_C

#include "soleil.hpp"

soleil::soleil() : c(color(1)) {lumiere = true;};
soleil::soleil(color col) : c(col) {lumiere = true;};

color soleil::couleur(hit_record h) const{
    return c;
};
vec3 soleil::rayon(hit_record h) const{
    return vec3(0);
};


#endif