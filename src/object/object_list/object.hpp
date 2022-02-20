#ifndef OBJECT_H
#define OBJECT_H

#include "./../../my_lib/my_lib.hpp"

class object {
    public:
        virtual double distance(vec3 pos) const = 0;
};

#endif