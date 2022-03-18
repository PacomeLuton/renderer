#pragma once

#include "./../my_lib/my_lib.h"

// On a l'integrale de la lumiere :
// emittance + INT(f(w0,wi)*L(wi)*(wi.n) , dwi)

class material {
    public:
        virtual color emittance(hit_record in) const = 0; // donne la lumiere emis par l'objet
        virtual color reflexion(hit_record in, color c, vec3 out) const = 0; // donne la couleur réfléchi
        virtual vec3 rayon(hit_record in) const = 0; // d'ou vient la lumiere incidente, si il y en a une
};