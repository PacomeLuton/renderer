#include "damier.hpp"

damier::damier() : couleur1(color(1)), couleur2(color(0.01)),maille(1) {};

damier::damier(color c1, color c2) : couleur1(c1), couleur2(c2),maille(1) {};
damier::damier(color c1, color c2, double m) : couleur1(c1), couleur2(c2), maille(m) {};

color damier::value(double u, double v) const {
    color res; u*=maille; v*=maille;
    u = u - floor(u); v = v - floor(v);
    if ((u < 0.5) ^ (v < 0.5)) res = couleur1;
    else res = couleur2;
    return res;
}
