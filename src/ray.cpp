#ifndef RAY_C
#define RAY_C

#include "my_lib/my_lib.h"
#include "object/all_objects.h"

hit_record map(vec3 pos, scene &world){
    hit_record d = world.hit(pos);
    return d;
}

// http://iquilezles.org/www/articles/normalsSDF/normalsSDF.htm
vec3 calcNormal(vec3 p, scene &world){
    const float h = 0.0001; 
    const vec2 k = vec2(1,-1);
    return unit_vector( vec3(1,-1,-1)*world.distance( p + vec3(1,-1,-1)*h) + 
                        vec3(-1,-1,1)*world.distance( p + vec3(-1,-1,1)*h) + 
                        vec3(-1,1,-1)*world.distance( p + vec3(-1,1,-1)*h) + 
                        vec3(1,1,1)*world.distance( p + vec3(1,1,1)*h));
}

hit_record ray_casting(vec3 ro, vec3 rd, scene &world){
    hit_record res;

    double tmax = 20.;
    double tmin = 0.01;

    double t = tmin;
    for(int i = 0; i < 256 && t < tmax; i++){
        vec3 pos = ro + rd*t;
        hit_record h = map(pos, world);
        if (abs(h.distance) < 0.001){
            res = h;
            res.time = t;
            break;
        }
        t+=abs(h.distance);
    }
    //if (t < tmax) res.t = t;
    return res;
}

#endif