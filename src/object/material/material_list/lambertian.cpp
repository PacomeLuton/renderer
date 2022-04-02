#include "lambertian.hpp"

color lambertian::BRDF(hit_record &h) const {
    return textu->value(h.u,h.v) / pi;
}  

color lambertian::emittance(hit_record &in) const {
    return color(0);
}
