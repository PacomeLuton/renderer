#include "miror.hpp"

color miror::emittance(hit_record &in) const {
    return color(0);
}

color miror::BRDF(hit_record &h) const {
    return textu->value(h.u,h.v); // pour le miroir on triche, vu qu'on sait que le rayon est toujours le même
} 