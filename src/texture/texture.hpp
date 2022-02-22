#ifndef TEXTURE_H
#define TEXTURE_H

#include "./../my_lib/my_lib.h"

class material {
    public:
        virtual color couleur(hit_record h) const = 0; // couleur de cette partie de l'objet
        virtual vec3 rayon(hit_record h) const = 0; // d'ou vient la lumiere
};

color material::couleur(hit_record h) const {
    return color(0);
}

#endif