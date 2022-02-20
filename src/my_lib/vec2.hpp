#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec2 {
    public:
        double e[2];
        
        vec2();
        vec2(double x);
        vec2(double e0, double e1);

        double x() const;
        double y() const;

        vec2 operator-() const;
        double operator[](int i) const;
        double& operator[](int i);

        vec2& operator+=(const vec2 &v);
        vec2& operator*=(const double t);
        vec2& operator/=(const double t);
        
        double norm() const;
        double length_squared() const;
};


inline std::ostream& operator<<(std::ostream &out, const vec2 &v);

inline vec2 operator+(const vec2 &u, const vec2 &v);
inline vec2 operator-(const vec2 &u, const vec2 &v);
inline vec2 operator*(const vec2 &u, const vec2 &v);
inline vec2 operator/(const vec2 &u, const vec2 &v);

inline vec2 operator*(double t, const vec2 &v);
inline vec2 operator*(const vec2 &v, double t);
inline vec2 operator/(vec2 v, double t);

inline double dot(const vec2 &u, const vec2 &v);
inline vec2 unit_vector(vec2 v);
inline double length(vec2 v);

#endif