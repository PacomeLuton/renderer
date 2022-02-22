#ifndef ALL_TEXTURE_H
#define ALL_TEXTURE_H

#include "texture.hpp"

#include <memory>
using std::shared_ptr;
using std::make_shared;

//https://raytracing.github.io/books/RayTracingInOneWeekend.html
#include "./texture_list/lambertian.cpp"
#include "./texture_list/uniform.cpp"
#include "./texture_list/miror.cpp"

#endif