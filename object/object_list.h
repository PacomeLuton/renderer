#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include <vector>
#include "./../my_lib/my_lib.h"

//https://iquilezles.org/www/articles/distfunctions/distfunctions.htm

#include "object.h"
#include "sphere.h"
#include "deathstar.h"
#include "torus.h"
#include "infinite_cylinder.h"
#include "stick.h"

using std::shared_ptr;
using std::make_shared;

class scene : public object {
    public:
        scene() {}
        scene(shared_ptr<object> o) { add(o); }

        void clear() { objects.clear(); }
        void add(shared_ptr<object> o) { objects.push_back(o); }

        virtual double distance(vec3 pos) const override;

    public:
        std::vector<shared_ptr<object>> objects;
};

double scene::distance(vec3 pos) const {
    double d = infinity;
    for(const auto& o : objects) {
        d = smin(d, o->distance(pos),0.05);
        //d = min(d, o->distance(pos));
    }
    return d;
}


#endif