//
// Created by 79096 on 12.07.2022.
//
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
struct Point{
    float x, y, z;

    bool is_valid() const{
        return !( x != x || y != y || z != z);
    };
    bool is_equal(const Point& other) const{
        assert(is_valid() && other.is_valid());
    };
};
struct vec{
    double X, Y, Z, size;
    vec(const Point& p1, const Point& p2){
        X = p1.x - p2.x; // координата направляющего вектора по х
        Y = p1.y - p2.y; // координата направляющего вектора по y
        Z = p1.z - p2.z; // координата направляющего вектора по z
        size = std::sqrt(X*X + Y*Y + Z*Z);
    }
};
struct Line{
    double size_of_line, x, y, z;
    constexpr Line (const vec& a){
        size_of_line = a.size;
        x = a.X;
        y = a.Y;
        z = a.Z;
    }

    bool is_intersect(Line& other){
        if(x)
    }

};

class Triangle3D{
    int x, y, z;
public:

};