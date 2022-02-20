#include "my_lib/my_lib.h"
#include "object/all_objects.h"

double map(vec3 pos, scene &world){
    double d = world.distance(pos);
    return d;
}

// http://iquilezles.org/www/articles/normalsSDF/normalsSDF.htm
vec3 calcNormal(vec3 p, scene &world){
    const float h = 0.0001; 
    const vec2 k = vec2(1,-1);
    return unit_vector( vec3(1,-1,-1)*map( p + vec3(1,-1,-1)*h, world) + 
                      vec3(-1,-1,1)*map( p + vec3(-1,-1,1)*h, world) + 
                      vec3(-1,1,-1)*map( p + vec3(-1,1,-1)*h, world) + 
                      vec3(1,1,1)*map( p + vec3(1,1,1)*h, world));
}

double ray_casting(vec3 ro, vec3 rd, scene &world){
    double res = -1;

    double tmax = 20.;
    double tmin = 0.01;

    double t = tmin;
    for(int i = 0; i < 256 && t < tmax; i++){
        vec3 pos = ro + rd*t;
        double h = map(pos, world);
        if (h < 0.001){
            res = t;
            break;
        }
        t+=h;
    }
    return res;
}