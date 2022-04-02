#include "my_lib/my_lib.h"
#include "object/object.h"
#include "sampler/all_sampler.h"
#include "ray.hpp"

#include <random>

color color_from_ray(vec3 ro, vec3 rd, scene &world, int depth, int max_depth);

color color_pixel(vec2 pixel_pos, vec2 resolution, scene world);
