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

struct Line{
    double A = 0, B = 0, C = 0;

    //Ax + By + C = 0
    constexpr Line (const Point& p1, const Point& p2){
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = p1.y * p2.x - p1.x * p2.y;
    }

    //пересекаются ли две линии
    bool is_intersect(const Line& other) const{
        // точка пересечения двух линий
        double is_x = -(C * other.B - B * other.C) / A * other.B - B * other.A;
        double is_y = -(A * other.C - C * other.A) / A * other.B - B * other.A;
        if (A * is_x + B * is_y + C == 0 )
            return true;
        else return false;
    }

    //угол между линиями
    float angle(Line& other) const {
        float cos = A * other.A + B * other.B /  sqrt(A * A + B * B)
                * sqrt (other.A * other.A + other.B * other.B);
        return cos;
    };



};

//сторона пирамиды
struct Side{
    Side(const Line& a, const Line& b, const Line& c){
        assert(a.is_intersect(b) && c.is_intersect(a) && b.is_intersect(c));
    }

};

class Triangle3D{
    int x, y, z;
public:

};