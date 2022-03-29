#include "lambertian.hpp"

vec3 lambertian::rayon(hit_record h) const {
    vec3 ray = unit_vector(h.normal + random_in_unit_sphere());
    return ray;
};

color lambertian::emittance(hit_record in) const {
    return color(0);
}
