#pragma once

#include "../object.hpp"

class plane : public object {
    private:
        vec3 normal;
        vec3 center;
        vec3 dir;
    
    public:
        plane();
        plane(vec3 n);
        plane(vec3 n, vec3 p);
        plane(vec3 n, vec3 p, vec3 dir);

        virtual double distance(vec3 pos) const override;
        virtual void coord_from_impact(vec3 pos, double &u, double &v) const override;
};
