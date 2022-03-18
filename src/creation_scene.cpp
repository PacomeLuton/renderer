#include "my_lib/my_lib.h"
#include "object/all_objects.h"

using std::shared_ptr;
using std::make_shared;

scene creation_scene(){
    scene world;
    //world.add(make_shared<sphere>(vec3(0),0.25));
    //world.add(make_shared<deathstar>(vec3(0),0.25,0.14,0.3));
    torus tor(vec3(0),0.4,0.1,vec3(-0.6,1,1.3));
    tor.set_material(make_shared<lambertian>(color(0.9,0.3,0.6)));
    world.add(make_shared<torus>(tor));

    infinite_cylinder bar(vec3(0),0.1,vec3(-0.6,1,1.3));
    bar.set_material(make_shared<lambertian>());
    //world.add(make_shared<infinite_cylinder>(bar));
    
    sphere boule(vec3(0.8,0.5,-0.3),0.18);
    boule.set_material(make_shared<miror>(color(0.8)));
    world.add(make_shared<sphere>(boule));

    sphere boule2(vec3(-0.8,0.5,-0.3),0.18);
    boule2.set_material(make_shared<miror>(color(0.9)));
    world.add(make_shared<sphere>(boule2));

    sphere sun(vec3(-0.5,0.6,0.5),0.1);
    sun.set_material(make_shared<soleil>());
    world.add(make_shared<sphere>(sun));

    sphere terre(vec3(0,-20,0),19.9); 
    terre.set_material(make_shared<lambertian>(color(0.2,1,0.4)));
    world.add(make_shared<sphere>(terre));


    return world;
}