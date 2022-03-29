#pragma once

#include "../texture.hpp"

class solid_color : public texture {
    private:
        color couleur;
    
    public:
        solid_color();
        solid_color(color c);
        virtual color value(double u, double v) const override;

};

