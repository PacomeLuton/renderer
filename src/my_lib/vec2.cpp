#include "vec2.hpp"

vec2::vec2() : e{0,0} {};
vec2::vec2(double x) : e{x,x} {};
vec2::vec2(double e0, double e1) : e{e0, e1} {};

double vec2::x() const { return e[0]; }
double vec2::y() const { return e[1]; }

vec2 vec2::operator-() const { return vec2(-e[0], -e[1]); }
double vec2::operator[](int i) const { return e[i]; }
double& vec2::operator[](int i) { return e[i]; }

vec2& vec2::operator+=(const vec2 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    return *this;
}

vec2& vec2::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    return *this;
}

vec2& vec2::operator/=(const double t) {
    return *this *= 1/t;
}

double vec2::norm() const {
    return sqrt(length_squared());
}

double vec2::length_squared() const{
    return e[0]*e[0] + e[1]*e[1];
}

std::ostream& operator<<(std::ostream &out, const vec2 &v) {
    return out << v.e[0] << ' ' << v.e[1];
}

vec2 operator+(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] + v.e[0], u.e[1] + v.e[1]);
}

vec2 operator-(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] - v.e[0], u.e[1] - v.e[1]);
}

vec2 operator*(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] * v.e[0], u.e[1] * v.e[1]);
}

vec2 operator/(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] / v.e[0], u.e[1] / v.e[1]);
}

vec2 operator*(double t, const vec2 &v) {
    return vec2(t*v.e[0], t*v.e[1]);
}

vec2 operator*(const vec2 &v, double t) {
    return t * v;
}

vec2 operator/(vec2 v, double t) {
    return (1/t) * v;
}

double dot(const vec2 &u, const vec2 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1];
}

vec2 unit_vector(vec2 v) {
    return v / v.norm();
}

double length(vec2 v){
    return v.norm();
}