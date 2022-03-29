#ifndef STICK_H
#define STICK_H

#include "../object.hpp"

class stick : public object {
    public:
        vec3 center;
        double radius;
        double taille;
        vec3 axe;

    public:
        stick();
        stick(vec3 cen, double t, double r);
        stick(vec3 cen, double t, double r, vec3 a);

        virtual double distance(vec3 pos) const override;
        virtual void coord_from_impact(vec3 pos, double &u, double &v) const override;
};

#endif