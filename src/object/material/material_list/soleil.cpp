#include "soleil.hpp"

soleil::soleil() : couleur_emis(color(1)) {};
soleil::soleil(color emis) : couleur_emis(emis) {};

color soleil::emittance(hit_record &h) const {
    return couleur_emis;
};

color soleil::BRDF(hit_record &h) const {
    return color(0);
} 

