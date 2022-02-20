#include "my_lib/my_lib.h"
#include "ray.h"
#include "object/all_objects.h"

color color_pixel(vec2 pixel_pos, vec2 resolution){
    vec2 p = (2*pixel_pos - resolution)/resolution.y();
    
    color c;

    scene world;
    //world.add(make_shared<sphere>(vec3(0),0.25));
    //world.add(make_shared<deathstar>(vec3(0),0.25,0.14,0.3));
    world.add(make_shared<torus>(vec3(0),0.4,0.1,vec3(-0.6,1,1.3)));
    world.add(make_shared<infinite_cylinder>(vec3(0),0.1,vec3(-0.6,1,1.3)));
    //world.add(make_shared<stick>(vec3(0,-0.3,0),0.8,0.16,vec3(0,1,0)));
    //world.add(make_shared<sphere>(vec3(0.25,0,0),0.18));
    //world.add(make_shared<sphere>(vec3(-0.25,0,0),0.18));
    world.add(make_shared<sphere>(vec3(0,-20,0),19.9));

    vec3 ro = vec3(0,0.3,1);
    vec3 rd = unit_vector(vec3(p,-1.5));

    auto t = ray_casting(ro,rd,world);
    if (t > 0){
        vec3 n = unit_vector(calcNormal(ro+rd*t,world));
        vec3 sun_dir = unit_vector(vec3(0.6, 0.35, 0.5));
        auto h = ray_casting(ro+rd*t+0.01*n,sun_dir,world);
        if (h > 0) c = color(0);
        else c = clamp(dot(n,sun_dir),0,1)*color(0.5);
        c += 0.1*color(0.5, 0.7, 1.0);
    }else{
        color background_color = (p.y()+1)/2*color(0.5, 0.7, 1.0) + (1-(p.y()+1)/2)*color(1.0, 1.0, 1.0);
        c = background_color;
    }

    return c;
}