#ifndef TEXTURE_SOLEIL_C
#define TEXTURE_SOLEIL_C

#include "soleil.hpp"

soleil::soleil() : couleur_emis(color(1)) {};
soleil::soleil(color emis) : couleur_emis(emis) {};

color soleil::emittance(hit_record h) const {
    return this->couleur_emis;
};

color soleil::reflexion(hit_record in, color c, vec3 out) const {
    return color(0);
}

vec3 soleil::rayon(hit_record h) const {
    return vec3(0); 
}

#endif