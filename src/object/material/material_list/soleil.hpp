#pragma once

#include "../material.hpp"

class soleil : public material {
    private:
        color couleur_emis;
    public:
        soleil();
        soleil(color e);

        virtual color emittance(hit_record &in) const override;
        virtual color BRDF(hit_record &h) const override;
};
