#ifndef TORUS_H
#define TORUS_H

#include "object.h"
#include "./../my_lib/my_lib.h"

class torus : public object {
    public:
        torus() {}
        torus(vec3 cen, double r, double e) : center(cen), radius(r), epaisseur(e) {};
        torus(vec3 cen, double r, double e, vec3 a) : center(cen), radius(r), epaisseur(e), axe(unit_vector(a)) {};

        virtual double distance(vec3 pos) const override;

    public:
        vec3 center;
        double radius;
        double epaisseur;
        vec3 axe;

};

double torus::distance(vec3 pos) const {
    vec3 p = pos-center;
    vec2 q = vec2(length(p-axe*dot(axe,p))-radius,dot(axe,p));
    return length(q)-epaisseur;
}


#endif