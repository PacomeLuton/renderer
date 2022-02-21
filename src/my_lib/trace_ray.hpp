#ifndef TRACE_RAY_H
#define TRACE_RAY_H

#include "vec3.hpp"

struct hit_record {
    vec3 p; // position ou ça a touché
    vec3 n; // normal de la surface (calculer si besoin)
    double d; // distance à la surface
    double t; // distance au depart du rayon
    bool front_face; // interieur ou exterieur de la surface
    color c; // couleur de la surface

    hit_record(){
        this->t = -1;
        this->c = color(0.5);
    }
};

#endif