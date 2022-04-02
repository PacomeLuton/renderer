#include "material.hpp"

void material::set_texture(shared_ptr<texture> t){
    textu = t;
}

void material::set_texture(color c){
    textu = make_shared<solid_color>(c);
}