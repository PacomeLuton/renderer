#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
#include "vec2.hpp"
#include "utils.hpp"

using std::sqrt;

class vec3 {
    public:
        double e[3];

    public:
        vec3();
        vec3(double x);
        vec3(double e0, double e1, double e2);
        vec3(vec2 v, double x);

        double x() const;
        double y() const;
        double z() const;
        vec2 xy() const;
        vec2 xz() const;
        vec2 yz() const;

        vec3 operator-() const;
        double operator[](int i) const;
        double& operator[](int i);

        vec3& operator+=(const vec3 &v);
        vec3& operator*=(const double t);
        vec3& operator/=(const double t);

        double norm() const;
        double length_squared() const;

        static vec3 random();
        static vec3 random(double min, double max);
        static vec3 random_unit();
};


std::ostream& operator<<(std::ostream &out, const vec3 &v);

vec3 operator+(const vec3 &u, const vec3 &v);
vec3 operator-(const vec3 &u, const vec3 &v);
vec3 operator*(const vec3 &u, const vec3 &v);

vec3 operator*(double t, const vec3 &v);
vec3 operator*(const vec3 &v, double t);
vec3 operator/(vec3 v, double t);

vec3 power(vec3 v, double t);
vec3 max(vec3 a, vec3 b);
vec3 min(vec3 a, vec3 b);
vec3 abs(vec3 a);

double dot(const vec3 &u, const vec3 &v);
vec3 cross(const vec3 &u, const vec3 &v);

vec3 unit_vector(vec3 v);
double length(vec3 v);
bool close_null(vec3 v);

vec3 random_in_unit_sphere();
vec3 random_unit_vector();

using color = vec3;    // RGB color

#endif