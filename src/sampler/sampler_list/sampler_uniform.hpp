#pragma once

#include "./../sampler.hpp"

class sampler_uniform : public sampler{
    private:
        virtual double pdf(hit_record &h) const override;

    public:
        virtual vec3 rayon(hit_record &h) const override;
        virtual color integrate(hit_record &h, color in) const override;
    
};