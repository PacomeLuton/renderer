#ifndef TRACE_RAY_H
#define TRACE_RAY_H

#include "vec3.hpp"
#include <memory>

class material;
class sampler;

struct hit_record {
    vec3 pos; // position ou ça a touché
    vec3 normal; // normal de la surface (calculer si besoin)
    vec3 wi; // direction du rayon incident (la ou est l'observateur)
    vec3 wo; // direction du rayon sortant (la d'ou vient la lumiere)
    
    double distance; // distance à la surface
    double time; // distance au depart du rayon
    
    bool front_face; // interieur ou exterieur de la surface
    
    double u; // position de l'impact dans les coordonnés de l'objet
    double v; // position de l'impact dans les coordonnés de l'obje
    
    std::shared_ptr<material> mat; //materiel decrivant la surface

    hit_record(){
        time = -1; //par convention, si le rayon touche rien on le mets à -1
        mat = nullptr; //si on a pas encore touche de materiaux, ce pointeur est nul
        u = 0;
        v = 0;
    }
};

#endif