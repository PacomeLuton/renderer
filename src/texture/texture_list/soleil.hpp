#ifndef TEXTURE_SOLEIL_H
#define TEXTURE_SOLEIL_H

#include "../texture.hpp"

class soleil : public material {
    public:
        color c;
    public:
        soleil();
        soleil(color c);
        virtual color couleur(hit_record h) const override;
        virtual vec3 rayon(hit_record h) const override;
};


#endif