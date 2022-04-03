#include "creation_scene.hpp"

/*
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
*/
void cube_on_damier(scene &world){
    lambertian psucre; psucre.set_texture(color(0.5,0.2,0.1)); auto sucre = make_shared<lambertian>(psucre);
    lambertian pdam; pdam.set_texture(make_shared<damier>(0.9,0.03,2)); auto dam = make_shared<lambertian>(pdam);
    soleil plight(color(1, 1, 1)); auto light = make_shared<soleil>(plight);

    square carre(vec3(0,0.4,-1),vec3(0.3), mat3::rotationY(0.7));
    carre.set_material(sucre);
    world.add(make_shared<square>(carre));

    plane sol;
    sol.set_material(dam);
    world.add(make_shared<plane>(sol));

    plane ciel(vec3(0,1,0), vec3(0,20,0));
    ciel.set_material(light);
    world.add(make_shared<plane>(ciel));
}


void cornellBox(scene &world){
    sampler_light s1; s1.add_light(vec3(0,2,0), vec3(0,-1,0), 0.8);
    auto ss1 = make_shared<sampler_light>(s1);

    sampler_uniform s2; auto ss2 = make_shared<sampler_uniform>(s2);

    sampler_smart s; s.s1 = ss1; s.s2 = ss2; s.p = 0.2;
    auto ss = make_shared<sampler_smart>(s);
    
    lambertian pred; pred.set_texture(color(.65, .05, .05)); auto red = make_shared<lambertian>(pred); red->sampl =ss2;
    lambertian pwhite; pwhite.set_texture(color(.73, .73, .73)); auto white = make_shared<lambertian>(pwhite); white->sampl = ss2;
    lambertian pgreen; pgreen.set_texture(color(.12, .45, .15)); auto green = make_shared<lambertian>(pgreen); green->sampl = ss2;
    soleil plight(color(5)); auto light = make_shared<soleil>(plight); light->sampl = ss2;

    plane gauche(vec3(1,0,0), vec3(-2,0,0)); gauche.set_material(green);
    plane droite(vec3(-1,0,0), vec3(2,0,0)); droite.set_material(red);
    plane haut(vec3(0,-1,0), vec3(0,2,0)); haut.set_material(white);
    plane bas(vec3(0,1,0), vec3(0,-2,0)); bas.set_material(white);
    plane derriere(vec3(0,0,1), vec3(0,0,-2)); derriere.set_material(white);
    plane devant(vec3(0,0,-1), vec3(0,0,2)); devant.set_material(white);

    world.add(make_shared<plane>(gauche));
    world.add(make_shared<plane>(droite));
    world.add(make_shared<plane>(haut));
    world.add(make_shared<plane>(bas));
    world.add(make_shared<plane>(derriere));
    world.add(make_shared<plane>(devant));

    square l(vec3(0,2.49,0),vec3(0.5,0.5,0.5)); l.set_material(light);
    world.add(make_shared<square>(l));

    square c1(vec3(-0.8,-1,-0.2),vec3(0.57,1.4,0.57), mat3::rotationY(-0.25)); c1.set_material(white);
    world.add(make_shared<square>(c1));
    
    square c2(vec3(0.5,-1.4,0.8),vec3(0.6,0.6,0.6), mat3::rotationY(0.3)); c2.set_material(white);
    world.add(make_shared<square>(c2));
}

scene creation_scene(){
    scene world;
    //world.add(make_shared<sphere>(vec3(0),0.25));
    //world.add(make_shared<deathstar>(vec3(0),0.25,0.14,0.3));
    
    //donut_scene(world);
    //cube_on_damier(world);
    cornellBox(world);

    return world;
}