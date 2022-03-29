#include "stick.hpp"

stick::stick() {}
stick::stick(vec3 cen, double t, double r) : center(cen), taille(t), radius(r), axe(unit_vector(vec3(1))) {};
stick::stick(vec3 cen, double t, double r, vec3 a) : center(cen), taille(t), radius(r), axe(unit_vector(a)) {};
  
double stick::distance(vec3 pos) const {
    vec3 p = pos-center;
    double a = clamp(dot(p,axe),0,taille);
    return length(p-a*axe)-radius;
}

//pas encore implémenté
void stick::coord_from_impact(vec3 pos, double &u, double &v) const {
    vec3 p = pos-center;
    u = 0;
    v = 0;
}