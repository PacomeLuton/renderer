#pragma once

#include "mat3.hpp"

using std::sqrt;

mat3::mat3() {};
mat3::mat3(double x) {};
mat3::mat3(vec3 l0, vec3 l1, vec3 l2) {};

mat3 mat3::operator-() const { return mat3(-vec3(e[0][0],e[0][1],e[0][2]),-vec3(e[1][0],e[1][1],e[1][2]),-vec3(e[2][0],e[2][1],e[2][2])); }
vec3 mat3::operator[](int i) const { return vec3(e[i][0], e[i][1], e[2][2]); }

mat3& mat3::operator+=(const mat3 &v) {
    for(int i = 0; i < 3; i++) for(int j = 0; j< 3; j++) e[i][j] += v[i][j];
};

mat3& mat3::operator*=(const double t) {
    for(int i = 0; i < 3; i++) for(int j = 0; j< 3; j++) e[i][j] *= t;
};

mat3& mat3::operator/=(const double t) {
    for(int i = 0; i < 3; i++) for(int j = 0; j< 3; j++) e[i][j] /= t;
};


inline std::ostream& operator<<(std::ostream &out, const mat3 &v){
    return out << v[0][0] << " " << v[0][1] << " " << v[0][2] << "\n"
               << v[1][0] << " " << v[1][1] << " " << v[1][2] << "\n"
               << v[2][0] << " " << v[2][1] << " " << v[2][2];
};

//operation entre les matrice
inline mat3 operator+(const mat3 &u, const mat3 &v){
    return mat3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
};

inline mat3 operator-(const mat3 &u, const mat3 &v){
    return mat3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}

mat3 operator*(const mat3 &u, const mat3 &v){
    mat3 res(0);
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++){
        res[i][j] += u[i][k]*v[k][j];
    }
    return res;
}

//operation avec un vecteur;
inline vec3 operator*(const mat3 &u, const vec3 &v){
    return vec3(u[0][0]*v[0] + u[0][1]*v[1] + u[0][2]*v[2],
                u[1][0]*v[0] + u[1][1]*v[1] + u[1][2]*v[2],
                u[2][0]*v[0] + u[2][1]*v[1] + u[2][2]*v[2]);
};

//operation avec un scalaire
inline mat3 operator*(double t, const mat3 &v) {
    return mat3(t*v[0],t*v[1],t*v[2]);
};

inline mat3 operator*(const mat3 &v, double t) {
    return t*v;
};

inline mat3 operator/(mat3 v, double t) {
    return (1/t)*v;
};
