#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>
#include "object_list/object.hpp"

using std::shared_ptr;
using std::make_shared;

class scene : public object {
    public:
        scene();
        scene(shared_ptr<object> o);

        void clear();
        void add(shared_ptr<object> o);

        virtual double distance(vec3 pos) const override;

    public:
        std::vector<shared_ptr<object> > objects;
};

#endif