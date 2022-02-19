#ifndef STICK_H
#define STICK_H

#include "object.h"
#include "./../my_lib/my_lib.h"

class stick : public object {
    public:
        stick() {}
        stick(vec3 cen, double t, double r) : center(cen), taille(t), radius(r), axe(unit_vector(vec3(1))) {};
        stick(vec3 cen, double t, double r, vec3 a) : center(cen), taille(t), radius(r), axe(unit_vector(a)) {};

        virtual double distance(vec3 pos) const override;

    public:
        vec3 center;
        double radius;
        double taille;
        vec3 axe;

};

double stick::distance(vec3 pos) const {
    vec3 p = pos-center;
    double a = clamp(dot(p,axe),0,taille);
    return length(p-a*axe)-radius;
}


#endif