#pragma once

#include <vector>
#include <memory>

#include "forme/object.hpp"

using std::shared_ptr;
using std::make_shared;

class scene {
    private:
        std::vector<shared_ptr<object> > objects;

    public:
        scene();
        scene(shared_ptr<object> o);

        void clear();
        void add(shared_ptr<object> o);

        double distance(vec3 pos);
        hit_record hit(vec3 pos);

};