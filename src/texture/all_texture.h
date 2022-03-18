#pragma once

#include "texture.hpp"

#include <memory>
using std::shared_ptr;
using std::make_shared;

//https://raytracing.github.io/books/RayTracingInOneWeekend.html
#include "./texture_list/lambertian.cpp"
#include "./texture_list/miror.cpp"
#include "./texture_list/soleil.cpp"
#include "./texture_list/damier.cpp" //lambertian
