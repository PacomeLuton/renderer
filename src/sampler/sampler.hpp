#pragma once

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "./../my_lib/my_lib.h"
#include "./../object/material/material.hpp"

// On a l'integrale de la lumiere :
// emittance + INT(f(w0,wi)*L(wi)*(wi.n) , dwi)

class sampler {
    private:
        virtual double pdf(hit_record &h) const = 0;

    public:
        virtual vec3 rayon(hit_record &h) const = 0;
        virtual color integrate(hit_record &h, color in) const = 0;

};