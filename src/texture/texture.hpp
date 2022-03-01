#ifndef TEXTURE_H
#define TEXTURE_H

#include "./../my_lib/my_lib.h"

class material {
    public:
        bool reflexion = false; // si le material produit un rayon incident
        bool lumiere = false; // si le material produit de la lumière 
        double p = 1; //pourcentage venant de la lumiere direct
    public:
        virtual color couleur(hit_record h) const = 0; // couleur de cette partie de l'objet
        virtual vec3 rayon(hit_record h) const = 0; // d'ou vient la lumiere
};

color material::couleur(hit_record h) const {
    return color(0);
}

vec3 material::rayon(hit_record h) const {
    return vec3(0);
}

#endif