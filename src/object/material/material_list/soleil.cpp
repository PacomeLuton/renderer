#include "soleil.hpp"

soleil::soleil() : couleur_emis(color(1)) {};
soleil::soleil(color emis) : couleur_emis(emis) {};

color soleil::emittance(hit_record h) const {
    return this->couleur_emis;
};

vec3 soleil::rayon(hit_record h) const {
    return vec3(0); 
}
