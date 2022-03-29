#pragma once

#include "./../../my_lib/my_lib.h"
#include "./../material/all_material.h"

class object {
    public:
        shared_ptr<material> mat;
    public:
        object();
        virtual double distance(vec3 pos) const = 0;
        virtual void coord_from_impact(vec3 pos, double &u, double &v) const = 0;

        hit_record hit(vec3 pos);
        void set_material(shared_ptr<material> m);
};
