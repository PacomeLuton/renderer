#ifndef TORUS_H
#define TORUS_H

#include "../object.hpp"

class torus : public object {
    public:
        vec3 center;
        double radius;
        double epaisseur;
        vec3 axe;

    public:
        torus();
        torus(vec3 cen, double r, double e);
        torus(vec3 cen, double r, double e, vec3 a);

        virtual double distance(vec3 pos) const override;
        virtual void coord_from_impact(vec3 pos, double &u, double &v) const override;

};

#endif