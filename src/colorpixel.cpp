#include "colorpixel.hpp"

color color_from_ray(vec3 ro, vec3 rd, scene &world, int depth, int max_depth){
    if (depth > max_depth) return color(0); //le rayon a plus d'énergie

    color c = color(0);

    auto t = ray_casting(ro,rd,world); // on tire le rayon

    if (t.time > 0){ // on a touché un objet

        t.pos = ro+rd*t.time; //position du point d'impact
        t.normal = unit_vector(calcNormal(t.pos,world)); //on calcul la normal de la surface, car c'est paratique
        t.wi = -rd; // direction du rayon incident
        
        //vec3 sun_dir = unit_vector(vec3(0.6, 0.35, 0.5)); //direction du soleil
        //auto h = ray_casting(t.pos,sun_dir,world); // illumination directe
        //if (h.t < 0 && dot(sun_dir,t.n) > 0) c += 0.4*t.m->p*clamp(dot(t.n,sun_dir),0,1)*t.m->couleur(t); // si on a touché le soleil

        //couleur emise :
        c += t.mat->emittance(t);

        //couleur reflechi :
        vec3 new_direc = t.mat->rayon(t); // direction d'ou vient le rayon
        color c_temp = color_from_ray(t.pos,new_direc, world, depth+1, max_depth); // couleur qui arrive
        c += t.mat->reflexion(t,c_temp); // on met a jour la couleur
    
    } else { // on est arrivé à l'infini
        color background_color = power(color(2,3,20)/255,1/0.45);
        c = background_color;
    }

    return c;
}

color color_pixel(vec2 pixel_pos, vec2 resolution, scene world){
    color c;

    vec2 p = (2*pixel_pos - resolution)/resolution.y();

    //Pour la scene avec le sucre 
    //vec3 ro = vec3(0,1,1); //position de la camera
    //vec3 rd = unit_vector(vec3(p,-1.5)); //direction dans laquelle on regarde 
    //rd = mat3::rotationX(-0.44)*rd; // on baisse un peu la camera
    
    //pour la cornell BOX
    vec3 ro = vec3(2*p,2); //position de la camera
    vec3 rd = unit_vector(vec3(2*p,-8)); 


    c = color_from_ray(ro,rd,world,0,5);


    return c;
}

