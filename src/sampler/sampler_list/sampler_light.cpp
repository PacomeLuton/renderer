#include "sampler_light.hpp"

sampler_light::sampler_light() : surface(0,0,0) {};

double sampler_light::pdf(hit_record &h) const {
    vec3 to_light = h.wo;
    double d = to_light.length_squared();
    double area = pi*surface.rayon*surface.rayon;
    double ca = abs(dot(unit_vector(to_light), surface.normal) );
    return (d*d) / (ca * area);
}

vec3 sampler_light::rayon(hit_record &h) const {
    vec3 res;
    vec3 x = cross(random_unit_vector(), surface.normal);
    vec3 y = cross(surface.normal,x);

    double theta = random_double(0,2*pi);

    vec3 pos = surface.center + random_double(0,surface.rayon)*(x*cos(theta) + y*sin(theta));
    
    return pos - h.pos;

}

color sampler_light::integrate(hit_record &h, color in) const {
    color brdf = h.mat->BRDF(h);
    return brdf * in * dot(h.normal,unit_vector(h.wo)) / pdf(h);
}

void sampler_light::add_light(vec3 c, vec3 n, double r ){
    light_surface o(c,n,r);
    surface = o;
}
    