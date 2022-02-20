#ifndef INFINITE_CYLINDER_H
#define INFINITE_CYLINDER_H

#include "object.hpp"

class infinite_cylinder : public object {
    public:
        vec3 center;
        double radius;
        vec3 axe;
        
    public:
        infinite_cylinder();
        infinite_cylinder(vec3 cen, double r);
        infinite_cylinder(vec3 cen, double r, vec3 a);

        virtual double distance(vec3 pos) const override;

};

#endif