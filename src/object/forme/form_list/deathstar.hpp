#pragma once

#include "../object.hpp"

class deathstar : public object {
    public:
        vec3 center;
        double radiusA;
        double radiusB;
        double dis;
        vec3 axe;
        
    public:
        deathstar();
        deathstar(vec3 cen, double ra, double rb, double d);
        deathstar(vec3 cen, double ra, double rb, double d, vec3 a);

        virtual double distance(vec3 pos) const override;
         virtual void coord_from_impact(vec3 pos, double &u, double &v) const override;
};