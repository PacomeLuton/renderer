#pragma once

#include "material.hpp"

#include <memory>
using std::shared_ptr;
using std::make_shared;

//https://raytracing.github.io/books/RayTracingInOneWeekend.html
#include "./material_list/lambertian.hpp"
#include "./material_list/miror.hpp"
#include "./material_list/soleil.hpp"
