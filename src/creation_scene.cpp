#include "creation_scene.hpp"


static void donut_scene(scene &world){
    torus tor(vec3(0),0.4,0.1,vec3(-0.6,1,1.3));
    tor.set_material(make_shared<lambertian>(color(0.9,0.3,0.6)));
    world.add(make_shared<torus>(tor));

    //infinite_cylinder bar(vec3(0),0.1,vec3(-0.6,1,1.3));
    //bar.set_material(make_shared<lambertian>());
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
}

void cube_on_damier(scene &world){
    square carre(vec3(0,0.4,-1),vec3(0.3), mat3::rotationY(0.7));
    carre.set_material(make_shared<lambertian>(color(0.5,0.2,0.1)));
    //world.add(make_shared<square>(carre));

    plane sol;
    sol.set_material(make_shared<damier>());
    world.add(make_shared<plane>(sol));

    plane ciel(vec3(0,1,0), vec3(0,20,0));
    ciel.set_material(make_shared<soleil>(vec3(1)));
    world.add(make_shared<plane>(ciel));
}

scene creation_scene(){
    scene world;
    //world.add(make_shared<sphere>(vec3(0),0.25));
    //world.add(make_shared<deathstar>(vec3(0),0.25,0.14,0.3));
    
    //donut_scene(world);
    cube_on_damier(world);


    return world;
}