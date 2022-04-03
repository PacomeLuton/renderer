#pragma once

#include "./../sampler.hpp"
#include "./../../my_lib/my_lib.h"

struct light_surface{
    vec3 center;
    vec3 normal;
    double rayon;

    light_surface(vec3 c, vec3 n, double r) : center(c), normal(n), rayon(r) {}
};

class sampler_light : public sampler{
    private:
        light_surface surface;
        
    public:
        sampler_light();
        virtual double pdf(hit_record &h) const override;
        virtual vec3 rayon(hit_record &h) const override;
        virtual color integrate(hit_record &h, color in) const override;

        void add_light(vec3 c, vec3 n, double r);
    
};