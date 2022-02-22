#ifndef DEATHSTAR_C
#define DEATHSTAR_C

#include "deathstar.hpp"

deathstar::deathstar() {}
deathstar::deathstar(vec3 cen, double ra, double rb, double d) : center(cen), radiusA(ra), radiusB(rb), dis(d), axe(unit_vector(vec3(1,0.3,2))) {};
deathstar::deathstar(vec3 cen, double ra, double rb, double d, vec3 a) : center(cen), radiusA(ra), radiusB(rb), dis(d), axe(unit_vector(a)) {};

//https://iquilezles.org/www/articles/distfunctions/distfunctions.htm
double deathstar::distance(vec3 pos) const {
    double ra = radiusA;
    double rb = radiusB;
    double d = dis;
    double a = (ra*ra - rb*rb + d*d)/(2.0*d);
    double b = sqrt(max(ra*ra-a*a,0.0));
	
    vec3 p2 = pos-center;
    // sampling dependant computations
    double sca = dot(p2,axe);
    vec2 p = vec2(sca , length(p2-sca*axe) );

    if( p.x()*b-p.y()*a > d*max(b-p.y(),0.0) )
    {
        return length(p-vec2(a,b));
    }
    else
    {
        return max( (length(p          )-ra),
                   -(length(p-vec2(d,0))-rb));
    }
}

#endif