#ifndef TEXTURE_MIROR_H
#define TEXTURE_MIROR_H

#include "../texture.hpp"

class miror : public material {
    public:
        color couleur;
    public:
        miror();
        miror(color c);
        virtual color reflexion(hit_record in, color c, vec3 out) const override;
        virtual color emittance(hit_record in) const override;
        virtual vec3 rayon(hit_record in) const override;
};

#endif