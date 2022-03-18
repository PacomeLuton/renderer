#pragma once

#include "texture.hpp"

#include <memory>
using std::shared_ptr;
using std::make_shared;

//https://raytracing.github.io/books/RayTracingInOneWeekend.html
#include "./texture_list/lambertian.hpp"
#include "./texture_list/miror.hpp"
#include "./texture_list/soleil.hpp"
#include "./texture_list/damier.hpp" //lambertian
