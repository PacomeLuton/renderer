#ifndef TEXTURE_LAMBERTIAN_H
#define TEXTURE_LAMBERTIAN_H

#include "../texture.hpp"

class lambertian : public material {
    public:
        color c;
    public:
        lambertian();
        virtual color couleur(hit_record h) const override;
        virtual vec3 rayon(hit_record h) const override;
};

#endif