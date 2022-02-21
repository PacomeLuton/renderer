#ifndef COLOR_PIXEL_H
#define COLOR_PIXEL_H

#include "my_lib/my_lib.h"
#include "object/all_objects.h"
#include "ray.cpp"
#include "creation_scene.cpp"

color color_pixel(vec2 pixel_pos, vec2 resolution){
    vec2 p = (2*pixel_pos - resolution)/resolution.y();
    
    color c;

    scene world = creation_scene();

    vec3 ro = vec3(0,0.3,1);
    vec3 rd = unit_vector(vec3(p,-1.5));

    auto t = ray_casting(ro,rd,world);
    if (t.t > 0){
        vec3 n = unit_vector(calcNormal(ro+rd*t.t,world));
        vec3 sun_dir = unit_vector(vec3(0.6, 0.35, 0.5));
        auto h = ray_casting(ro+rd*t.t+0.005*n,sun_dir,world);
        if (h.t > 0 || dot(sun_dir,n) < 0) c = color(0);
        else c = clamp(dot(n,sun_dir),0,1)*t.c;
        c += 0.1*color(0.5, 0.7, 1.0);
    }else{
        color background_color = (p.y()+1)/2*color(0.5, 0.7, 1.0) + (1-(p.y()+1)/2)*color(1.0, 1.0, 1.0);
        c = background_color;
    }

    return c;
}


#endif