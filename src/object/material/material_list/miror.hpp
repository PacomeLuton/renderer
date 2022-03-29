#pragma once

#include "../material.hpp"

class miror : public material {
    public:
        virtual color emittance(hit_record in) const override;
        virtual vec3 rayon(hit_record in) const override;
};