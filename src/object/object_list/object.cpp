#ifndef OBJECT_C
#define OBJECT_C

#include "object.hpp"

void object::set_color(color c){
    this->couleur = c;
}

hit_record object::hit(vec3 pos){
    hit_record res;
    res.d = this->distance(pos);
    res.c = couleur;
    return res;
}

#endif