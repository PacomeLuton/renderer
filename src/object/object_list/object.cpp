#ifndef OBJECT_C
#define OBJECT_C

#include "object.hpp"
#include <memory.h>

object::object() : mat(std::make_shared<lambertian>()) {};

void object::set_material(shared_ptr<material> m){
    this->mat = m;
}

hit_record object::hit(vec3 pos){
    hit_record res;
    res.distance = this->distance(pos);
    res.mat = this->mat;
    res.front_face = (res.distance >= 0);
    return res;
}

#endif