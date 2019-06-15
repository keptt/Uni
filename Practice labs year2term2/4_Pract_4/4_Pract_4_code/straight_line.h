#ifndef STRAIGHT_LINE_H
#define STRAIGHT_LINE_H
#include <math.h>
#include <stdio.h>

struct point
{
    int x;
    int y;
    point(int x, int y);
    point();
};

class straight_line
{
    point a;
    point b;
public:
    straight_line();
    straight_line(point &one, point &two);
    straight_line(const straight_line &) = default;
    ~straight_line() = default;
    void print_equasion() const;
    void set_a(int x, int y);
    void set_b(int x, int y);
    void set_a(point a);
    void set_b(point b);
    inline point get_a() const;
    inline point get_b() const;
    bool operator||(const sstraight_line & line);
    double operator%(const sstraight_line & line);
};

#endif // STRAIGHT_LINE_H
