#pragma once

#include "../texture.hpp"

class damier : public texture {
    private:
        double maille = 1;
        color couleur1;
        color couleur2;
    
    public:
        damier();
        damier(color c1, color c2);
        damier(color c1, color c2, double m);

        virtual color value(double u, double v) const override;

};

