#pragma once

#include "../texture.hpp"

class damier : public material {
    private:
        color couleur1;
        color couleur2;
    public:
        damier();
        damier(color c1, color c2);
        virtual color reflexion(hit_record in, color c, vec3 out) const override;
        virtual color emittance(hit_record in) const override;
        virtual vec3 rayon(hit_record in) const override;
};