#include "torus.hpp"

torus::torus() {}
torus::torus(vec3 cen, double r, double e) : center(cen), radius(r), epaisseur(e) {};
torus::torus(vec3 cen, double r, double e, vec3 a) : center(cen), radius(r), epaisseur(e), axe(unit_vector(a)) {};

double torus::distance(vec3 pos) const {
    vec3 p = pos-center;
    vec2 q = vec2(length(p-axe*dot(axe,p))-radius,dot(axe,p));
    return length(q)-epaisseur;
}

//pas encore implémenté
void torus::coord_from_impact(vec3 pos, double &u, double &v) const {
    vec3 p = pos-center;
    u = 0;
    v = 0;
}