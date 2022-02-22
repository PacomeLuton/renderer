#ifndef OBJECT_C
#define OBJECT_C

#include "object.hpp"

object::object() : mat(std::make_shared<uniform_texture>()) {};

void object::set_color(color c){
    this->couleur = c;
}

void object::set_material(shared_ptr<material> m){
    this->mat = m;
}

color object::get_color(){
    return this->couleur;
}

hit_record object::hit(vec3 pos){
    hit_record res;
    res.d = this->distance(pos);
    res.c = this->get_color();
    res.m = this->mat;
    return res;
}

#endif