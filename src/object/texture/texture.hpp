#pragma once

#include "./../../my_lib/my_lib.h"

class texture {
    public:
        virtual color value(double u, double v) const = 0;
};