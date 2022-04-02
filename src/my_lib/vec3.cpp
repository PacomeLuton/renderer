#include "vec3.hpp"

vec3::vec3() : e{0,0,0} {}
vec3::vec3(double x) : e{x,x,x} {}
vec3::vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
vec3::vec3(vec2 v, double x) : e{v[0],v[1],x} {}

double vec3::x() const { return e[0]; }
double vec3::y() const { return e[1]; }
double vec3::z() const { return e[2]; }
vec2 vec3::xy() const { return vec2(e[0],e[1]); }
vec2 vec3::xz() const { return vec2(e[0],e[2]); }
vec2 vec3::yz() const { return vec2(e[1],e[2]); }

vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }
double vec3::operator[](int i) const { return e[i]; }
double& vec3::operator[](int i) { return e[i]; }

vec3& vec3::operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vec3& vec3::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec3& vec3::operator/=(const double t) {
    return *this *= 1/t;
}

double vec3::norm() const {
    return sqrt(length_squared());
}

double vec3::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

vec3 vec3::random() {
    return vec3(random_double(), random_double(), random_double());
}

vec3 vec3::random(double min, double max) {
    return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
}

vec3 vec3::random_unit(){
    return unit_vector(vec3::random(-1,1));
}


std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

vec3 power(vec3 v, double t){
    return vec3(pow(v.e[0],t), pow(v.e[1],t), pow(v.e[2],t));
}

vec3 max(vec3 a, vec3 b){
    return vec3(max(a.e[0],b.e[0]), max(a.e[1],b.e[1]), max(a.e[2],b.e[2]));   
};

vec3 min(vec3 a, vec3 b){
    return vec3(min(a.e[0],b.e[0]), min(a.e[1],b.e[1]), min(a.e[2],b.e[2]));   
};

vec3 abs(vec3 v){
    return vec3(std::abs(v.e[0]), std::abs(v.e[1]), std::abs(v.e[2]));
};

double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

vec3 unit_vector(vec3 v) {
    return v / v.norm();
}

double length(vec3 v){
    return v.norm();
}

bool close_null(vec3 v){
    return (length(v) < 1e-7);
}

vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3::random(-1,1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

vec3 random_hemi(vec3 n){
    while(true){
        auto p = random_unit_vector();
        if (dot(p,n) < 1e-6) continue;
        return p;
    }
}