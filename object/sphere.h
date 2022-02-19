#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "./../my_lib/my_lib.h"

class sphere : public object {
    public:
        sphere() {}
        sphere(vec3 cen, double r) : center(cen), radius(r) {};
        sphere(vec3 cen, double r, color c) : center(cen), radius(r) {};

        virtual double distance(vec3 pos) const override;

    public:
        vec3 center;
        double radius;
};

double sphere::distance(vec3 pos) const {
    vec3 v = pos-center;
    double d = v.norm();
    return d-radius;
}

#endif