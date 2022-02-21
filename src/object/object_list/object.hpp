#ifndef OBJECT_H
#define OBJECT_H

#include "./../../my_lib/my_lib.h"

class object {
    public:
        color couleur = color(0.5);
    public:
        virtual double distance(vec3 pos) const = 0;
        hit_record hit(vec3 pos);
        void set_color(color c);
};

#endif