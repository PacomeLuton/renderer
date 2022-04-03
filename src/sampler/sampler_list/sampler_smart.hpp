#pragma once

#include "./../sampler.hpp"

class sampler_smart: public sampler{  
        
    public:
        double p;
        shared_ptr<sampler> s1;
        shared_ptr<sampler> s2;
        virtual double pdf(hit_record &h) const override;
        virtual vec3 rayon(hit_record &h) const override;
        virtual color integrate(hit_record &h, color in) const override;
    
};