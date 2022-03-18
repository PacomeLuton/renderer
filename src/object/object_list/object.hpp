#ifndef OBJECT_H
#define OBJECT_H

#include "./../../my_lib/my_lib.h"
#include "./../../texture/all_texture.h"

class object {
    public:
        shared_ptr<material> mat;
    public:
        object();
        virtual double distance(vec3 pos) const = 0;
        hit_record hit(vec3 pos);
        void set_material(shared_ptr<material> m);
};

#endif