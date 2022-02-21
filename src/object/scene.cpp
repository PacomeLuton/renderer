#include "scene.hpp"

scene::scene() {}
scene::scene(shared_ptr<object> o) { add(o); }

void scene::clear() { objects.clear(); }
void scene::add(shared_ptr<object> o) { objects.push_back(o); }

double scene::distance(vec3 pos) const {
    double d = infinity;
    for(const auto& o : objects) {
        //d = smin(d, o->distance(pos),0.05);
        d = min(d, o->distance(pos));
    }
    return d;
}

hit_record scene::hit(vec3 pos){
    hit_record res; res.d = 1e8;
    for(const auto& o : objects) {
        hit_record h = o->hit(pos);
        if (abs(h.d) < abs(res.d)){
            res = h;
        }
        //d = smin(d, o->distance(pos),0.05);
        //d = min(d, o->distance(pos));
    }
    return res;
}