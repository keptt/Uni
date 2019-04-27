#pragma once

#include "point.h"

class LineEquation
{
    float k;
    float b;
public:
    LineEquation();
    LineEquation(float k, float b);
    LineEquation(const LineEquation& line);
    ~LineEquation();

    Point findIntersectionWithOx() const;
    Point findIntersectionWithOy() const;

    float get_k() const;
    float get_b() const;

    void set_k(float k);
    void set_b(float b);

    void printEquation() const;

    float operator%(const LineEquation &line);//find angle between lines
    bool operator&&(const LineEquation &line);//check perpendicularity
};
