#pragma once

#include "object.hpp"

class plane : public object {
    private:
        vec3 normal;
        vec3 center;
    
    public:
        plane();
        plane(vec3 n);
        plane(vec3 n, vec3 p);

        virtual double distance(vec3 pos) const override;
};
