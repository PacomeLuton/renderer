#pragma once

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "./../../my_lib/my_lib.h"
#include "./../texture/all_texture.h"

class sampler;

// On a l'integrale de la lumiere :
// emittance + INT(f(w0,wi)*L(wi)*(wi.n) , dwi)

class material {
    public:
        shared_ptr<texture> textu = make_shared<solid_color>(0);
        shared_ptr<sampler> sampl = nullptr; //le sampler pour ce materiau
   
    public:
            
        virtual color BRDF(hit_record &h) const = 0; // BRDF propre au mateiaux
        virtual color emittance(hit_record &in) const = 0; // donne la lumiere emis par l'objet

        void set_texture(shared_ptr<texture> t);
        void set_texture(color t);
};