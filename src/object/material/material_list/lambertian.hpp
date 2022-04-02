#pragma once

#include "../material.hpp"

class lambertian : public material {
    public:
        virtual color BRDF(hit_record &h) const override;
        virtual color emittance(hit_record &in) const override;

};