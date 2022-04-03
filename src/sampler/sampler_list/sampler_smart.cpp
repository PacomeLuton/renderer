#include "sampler_smart.hpp"

double sampler_smart::pdf(hit_record &h) const {
    return p*s1->pdf(h) + (1-p)*s2->pdf(h);
}

vec3 sampler_smart::rayon(hit_record &h) const {
    double rand = random_double();
    if (rand < p) return s1->rayon(h);
    return s2->rayon(h);
}

color sampler_smart::integrate(hit_record &h, color in) const {
    color brdf = h.mat->BRDF(h);
    return brdf * in * dot(h.normal,h.wo) / pdf(h);
}