#ifndef INFINITE_CYLINDER_H
#define INFINITE_CYLINDER_H

#include "object.h"
#include "./../my_lib/my_lib.h"

class infinite_cylinder : public object {
    public:
        infinite_cylinder() {}
        infinite_cylinder(vec3 cen, double r) : center(cen), radius(r), axe(unit_vector(vec3(1))) {};
        infinite_cylinder(vec3 cen, double r, vec3 a) : center(cen), radius(r), axe(unit_vector(a)) {};

        virtual double distance(vec3 pos) const override;

    public:
        vec3 center;
        double radius;
        vec3 axe;

};

double infinite_cylinder::distance(vec3 pos) const {
    vec3 p = pos-center;
    double a = dot(p,axe);
    return length(p-a*axe)-radius;
}


#endif