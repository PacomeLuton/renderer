#ifndef TEXTURE_MIROR_H
#define TEXTURE_MIROR_H

#include "../texture.hpp"

class miror : public material {
    public:
        color c;
    public:
        miror();
        virtual color couleur(hit_record h) const override;
        virtual vec3 rayon(hit_record h) const override;
};

#endif