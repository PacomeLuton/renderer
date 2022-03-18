#pragma once

#include "../texture.hpp"

class lambertian : public material {
    public:
        color couleur;
    public:
        lambertian();
        lambertian(color col);
        virtual color reflexion(hit_record in, color c, vec3 out) const override;
        virtual color emittance(hit_record in) const override;
        virtual vec3 rayon(hit_record in) const override;
};