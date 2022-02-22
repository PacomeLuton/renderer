#ifndef TEXTURE_UNIFORM_H
#define TEXTURE_UNIFORM_H

#include "../texture.hpp"

class uniform_texture : public material {
    public:
        color c;
    public:
        uniform_texture();
        uniform_texture(color c);
        virtual color couleur(hit_record h) const override;
        virtual vec3 rayon(hit_record h) const override;
};

#endif