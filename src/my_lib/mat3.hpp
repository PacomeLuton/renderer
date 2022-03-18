#pragma once

#include <cmath>
#include <iostream>
#include "vec3.hpp"

using std::sqrt;

class mat3 {
    public:
        double e[3][3];

    public:
        mat3();
        mat3(double x);
        mat3(vec3 l0, vec3 l1, vec3 l2);

        mat3 operator-() const;
        vec3 operator[](int i) const;

        mat3& operator+=(const mat3 &v);
        mat3& operator*=(const double t);
        mat3& operator/=(const double t);

        inline static mat3 identity();
        inline static mat3 rotationX(double theta);
        inline static mat3 rotationY(double theta);
        inline static mat3 rotationZ(double theta);
        static mat3 random(); //ATTENTION, c'est pas uniform, ça fait un peut n'importe quoi
};


inline std::ostream& operator<<(std::ostream &out, const mat3 &v);

//operation entre les matrice
inline mat3 operator+(const mat3 &u, const mat3 &v);
inline mat3 operator-(const mat3 &u, const mat3 &v);
inline mat3 operator*(const mat3 &u, const mat3 &v);

//operation avec un vecteur;
inline vec3 operator*(const mat3 &m, const vec3 &v);

//operation avec un scalaire
inline mat3 operator*(double t, const mat3 &v);
inline mat3 operator*(const mat3 &v, double t);
inline mat3 operator/(mat3 v, double t);