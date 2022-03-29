#pragma once

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "./../../my_lib/my_lib.h"
#include "./../texture/all_texture.h"

// On a l'integrale de la lumiere :
// emittance + INT(f(w0,wi)*L(wi)*(wi.n) , dwi)

class material {
    private:
        shared_ptr<texture> textu = make_shared<solid_color>(0);

    public:
        virtual color emittance(hit_record in) const = 0; // donne la lumiere emis par l'objet
        virtual vec3 rayon(hit_record in) const = 0; // d'ou vient la lumiere incidente, si il y en a une

        void set_texture(shared_ptr<texture> t);
        void set_texture(color t);

        color reflexion(hit_record in, color c); // donne la couleur réfléchi
};