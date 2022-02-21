#ifndef TEXTURE_H
#define TEXTURE_H

#include "./../my_lib/my_lib.h"

struct hit_record;

class material {
    public:
        virtual bool scatter() const = 0;
};

#endif