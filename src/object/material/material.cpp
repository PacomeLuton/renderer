#include "material.hpp"

color material::emittance(hit_record in) const {
    return color(0);
}


vec3 material::rayon(hit_record h) const {
    return vec3(0); 
    //par convention, si le rayon est nul, on dit qu'il y a pas de rayon reflechi
}

void material::set_texture(shared_ptr<texture> t){
    textu = t;
}

void material::set_texture(color c){
    textu = make_shared<solid_color>(c);
}

color material::reflexion(hit_record in, color c){
    if (textu == nullptr) return color(0,0,1);
    return textu->value(in.u,in.v) * c;
}