#ifndef RAY_H
#define RAY_H

#include "my_lib/my_lib.h"
#include "object/all_objects.h"

hit_record map(vec3 pos, scene &world);

// http://iquilezles.org/www/articles/normalsSDF/normalsSDF.htm
vec3 calcNormal(vec3 p, scene &world);

hit_record ray_casting(vec3 ro, vec3 rd, scene &world);

#endif