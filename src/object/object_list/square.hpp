#pragma once

#include "object.hpp"

class square : public object {
    private:
        vec3 center;
        vec3 dim;
    
    public:
        square();
        square(vec3 cen, vec3 dim);

        virtual double distance(vec3 pos) const override;
};
