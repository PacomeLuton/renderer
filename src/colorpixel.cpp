#ifndef COLOR_PIXEL_H
#define COLOR_PIXEL_H

#include "my_lib/my_lib.h"
#include "object/all_objects.h"
#include "ray.cpp"
#include "creation_scene.cpp"


color color_from_ray(vec3 ro, vec3 rd, scene world, double power ,int depth){
    if (depth < 0 || power < 0.1) return color(0); //le rayon a plus d'énergie

    color c = color(0);

    auto t = ray_casting(ro,rd,world); // on tire le rayon

    if (t.t > 0)
    { // on a touché un objet

        if (t.m->lumiere){
            c = t.m->couleur(t);
            return c;
        }

        t.n = unit_vector(calcNormal(ro+rd*t.t,world)); //on calcul la normal de la surface, car c'est paratique
        t.p = ro+rd*t.t; //position du point d'impact
        t.i = rd; // direction du rayon incident
        
        vec3 sun_dir = unit_vector(vec3(0.6, 0.35, 0.5)); //direction du soleil
        auto h = ray_casting(t.p,sun_dir,world); // illumination directe
        
        //if (h.t < 0 && dot(sun_dir,t.n) > 0) c += 0.4*t.m->p*clamp(dot(t.n,sun_dir),0,1)*t.m->couleur(t); // si on a touché le soleil

        if (t.m->reflexion){ //si on peut recupérer des rayons reflechi.
            color c_temp = color(0);
            int N = 10*power;
            if (t.m->p < 1e-4) N = 1;
            for(int i = 0; i < N; i++){
                vec3 new_direc = t.m->rayon(t);
                c_temp += (1-t.m->p)*t.m->couleur(t) * color_from_ray(t.p,new_direc, world, power*(1-t.m->p), depth-1);
            }
            c += c_temp/N;
        }
    } 
    else
    { // on est arrivé à l'infini
        double coeff = clamp(dot(rd, vec3(0,1,0)),0,1); // direction du ciel
        color background_color = coeff*color(0.5, 0.7, 1.0) + (1-coeff)*color(0.8, 0.9, 1.0);
        //if (depth == 10) c = background_color;
    }

    return c;
}

color color_pixel(vec2 pixel_pos, vec2 resolution){
    vec2 p = (2*pixel_pos - resolution)/resolution.y();
    
    color c;

    scene world = creation_scene();

    vec3 ro = vec3(0,0.3,1);
    vec3 rd = unit_vector(vec3(p,-1.5));

    c = color_from_ray(ro,rd,world,1,10);

    return c;
}


#endif