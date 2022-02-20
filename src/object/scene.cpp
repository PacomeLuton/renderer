#include "scene.hpp"

scene::scene() {}
scene::scene(shared_ptr<object> o) { add(o); }

void scene::clear() { objects.clear(); }
void scene::add(shared_ptr<object> o) { objects.push_back(o); }

double scene::distance(vec3 pos) const {
    double d = infinity;
    for(const auto& o : objects) {
        d = smin(d, o->distance(pos),0.05);
        //d = min(d, o->distance(pos));
    }
    return d;
}