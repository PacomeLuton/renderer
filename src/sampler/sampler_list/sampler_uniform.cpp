#include "sampler_uniform.hpp"

double sampler_uniform::pdf(hit_record &h) const {
    return 1/pi;
}

vec3 sampler_uniform::rayon(hit_record &h) const {
    return random_hemi(h.normal);
}

color sampler_uniform::integrate(hit_record &h, color in) const {
    color brdf = h.mat->BRDF(h);
    return brdf * in * dot(h.normal,h.wo) / pdf(h);
}