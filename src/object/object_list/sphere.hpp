#ifndef SPHERE_H
#define SPHERE_H

#include "object.hpp"

class sphere : public object {
    public:
        vec3 center;
        double radius;
    
    public:
        sphere();
        sphere(vec3 cen, double r);

        virtual double distance(vec3 pos) const override;
};

#endif