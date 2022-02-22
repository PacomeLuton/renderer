#include "my_lib/my_lib.h"
#include "object/all_objects.h"

scene creation_scene(){
    scene world;
    //world.add(make_shared<sphere>(vec3(0),0.25));
    //world.add(make_shared<deathstar>(vec3(0),0.25,0.14,0.3));
    torus tor(vec3(0),0.4,0.1,vec3(-0.6,1,1.3)); tor.set_color(color(0.7,0.4,0.4));
    tor.set_material(make_shared<uniform_texture>(color(0.7,0.4,0.4)));
    world.add(make_shared<torus>(tor));
    world.add(make_shared<infinite_cylinder>(vec3(0),0.1,vec3(-0.6,1,1.3)));
    //world.add(make_shared<stick>(vec3(0,-0.3,0),0.8,0.16,vec3(0,1,0)));
    //world.add(make_shared<sphere>(vec3(0.25,0,0),0.18));
    //world.add(make_shared<sphere>(vec3(-0.25,0,0),0.18));
    sphere terre(vec3(0,-20,0),19.9); 
    terre.set_material(make_shared<uniform_texture>(color(0.2,0.7,0.4)));
    world.add(make_shared<sphere>(terre));

    return world;
}