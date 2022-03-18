#pragma once

#include "object.hpp"

class square : public object {
    private:
        vec3 center = vec3(0);
        vec3 dim = vec3(1);
        mat3 rot = mat3::identity();

    public:
        square();
        square(vec3 cen, vec3 dim);
        square(vec3 cen, vec3 dim, mat3 r);

        virtual double distance(vec3 pos) const override;
};
