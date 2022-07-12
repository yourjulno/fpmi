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

//ребро пирамиды
struct Line{
    double A = 0, B = 0, C = 0;

    //Ax + By + C = 0
    constexpr Line (const Point& p1, const Point& p2){
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = p1.y * p2.x - p1.x * p2.y;
    }

    //пересекаются ли две линии
    bool is_line_intersect(const Line& other) const{
        // точка пересечения двух линий
        double is_x = -(C * other.B - B * other.C) / A * other.B - B * other.A;
        double is_y = -(A * other.C - C * other.A) / A * other.B - B * other.A;
        if (A * is_x + B * is_y + C == 0 )
            return true;
        else return false;
    }

    //угол между линиями
    float angle(const Line& other) const {
        float cos = A * other.A + B * other.B /  sqrt(A * A + B * B)
                * sqrt (other.A * other.A + other.B * other.B);
        return acos(cos);
    };



};

//грань пирамиды
struct Side{
    Line a_, b_, c_;
    Side(const Line& a, const Line& b, const Line& c): a_(a), b_(b), c_(c){
        assert(a.is_line_intersect(b) && c.is_line_intersect(a) && b.is_line_intersect(c));
        assert(a.angle(b) + b.angle(c) + c.angle(a) < 180);
    }

    //пересечение граней
    bool is_side_intersect(const Side& other) const{
        if (a_.is_line_intersect(other.a_) || a_.is_line_intersect(other.b_) || a_.is_line_intersect(other.c_)
        || b_.is_line_intersect(other.a_) || b_.is_line_intersect(other.b_) || b_.is_line_intersect(other.c_)
        || c_.is_line_intersect(other.a_) || c_.is_line_intersect(other.b_) || c_.is_line_intersect(other.c_))
            return true;
    }
};

//пирамида (состоит из четырёх граней, которые пересекаются по ребрам)
struct Triangle{
    Side s1_, s2_, s3_, s4_;
    constexpr Triangle(const Side& s1, const Side& s2, const Side& s3, const Side& s4): s1_(s1), s2_(s2),
    s3_(s3), s4_(s4){
        assert(s1_.is_side_intersect(s2_) && s2.is_side_intersect(s3_) && s3.is_side_intersect(s1_) && s1.is_side_intersect(s4_));
    }

    //пересечение пирамид
    bool is_triangle_intersect(const Triangle& other) const{

    }

};

class Triangle3D{
    int x, y, z;
public:

};