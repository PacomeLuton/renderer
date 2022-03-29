#include "solid_color.hpp"

solid_color::solid_color() : couleur(color(0.5)) {};

solid_color::solid_color(color c) : couleur(c) {};

color solid_color::value(double u, double v) const {
    return couleur;
}
