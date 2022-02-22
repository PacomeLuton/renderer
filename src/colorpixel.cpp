#ifndef COLOR_PIXEL_H
#define COLOR_PIXEL_H

#include "my_lib/my_lib.h"
#include "object/all_objects.h"
#include "ray.cpp"
#include "creation_scene.cpp"


color color_from_ray(vec3 ro, vec3 rd, scene world, int depth){
    if (depth < 0) return color(0); //le rayon a plus d'énergie

    color c = color(0);

    auto t = ray_casting(ro,rd,world); // on tire le rayon

    if (t.t > 0)
    { // on a touché un objet
        t.n = unit_vector(calcNormal(ro+rd*t.t,world)); //on calcul la normal de la surface, car c'est paratique
        t.p = ro+rd*t.t; //position du point d'impact
        t.i = rd; // direction du rayon incident
        
        vec3 sun_dir = unit_vector(vec3(0.6, 0.35, 0.5)); //direction du soleil
        auto h = ray_casting(t.p,sun_dir,world); // illumination directe
        
        if (h.t < 0 && dot(sun_dir,t.n) > 0) c += t.m->p*clamp(dot(t.n,sun_dir),0,1)*t.m->couleur(t); // si on a touché le soleil

        if (t.m->reflexion){ //si on peut recupérer des rayons reflechi.
            vec3 new_direc = t.m->rayon(t);
            c += (1-t.m->p)*t.m->couleur(t) * color_from_ray(t.p,new_direc, world, depth-1);

        }
    } 
    else
    { // on est arrivé à l'infini
        double coeff = clamp(dot(rd, vec3(0,1,0)),0,1); // direction du ciel
        color background_color = coeff*color(0.5, 0.7, 1.0) + (1-coeff)*color(0.8, 0.9, 1.0);
        c = background_color;
    }

    return c;
}

color color_pixel(vec2 pixel_pos, vec2 resolution){
    vec2 p = (2*pixel_pos - resolution)/resolution.y();
    
    color c;

    scene world = creation_scene();

    vec3 ro = vec3(0,0.3,1);
    vec3 rd = unit_vector(vec3(p,-1.5));

    c = color_from_ray(ro,rd,world,4);

    return c;
}


#endif