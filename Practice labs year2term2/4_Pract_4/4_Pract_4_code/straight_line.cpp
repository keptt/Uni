#include "straight_line.h"

point::point(int x, int y):x(x), y(y){}

point::point():x(1), y(1){}

straight_line::straight_line():a(1, 1), b(1, 1)
{
}

straight_line::straight_line(point &one, point &two):a(one), b(two)
{
}

void straight_line::print_equasion() const
{
    printf("%d*x + %d*y + %d = 0", a.y - b.y, b.x - a.x, a.x*b.y - b.x*a.y);
}

void straight_line::set_a(int x, int y)
{
    a.x = x;
    a.y = y;
}

void straight_line::set_b(int x, int y)
{
    b.x = x;
    b.y = y;
}

void straight_line::set_a(point a)
{
    straight_line::a = a;
}

void straight_line::set_b(point b)
{
    straight_line::b = b;
}

point straight_line::get_a() const
{
    return a;
}

point straight_line::get_b() const
{
    return b;
}

bool straight_line::operator||(const straight_line &line)
{
    return ((a.x % line.a.x == 0 ? true : false) && (b.x % line.b.x == 0 ? true : false)) || ((line.a.x % a.x == 0 ? true : false) && (line.b.x % b.x == 0 ? true : false));
}

double straight_line::operator%(const straight_line &line)
{
    point vec1 = point(b.x - a.x, b.y - a.y);
    point vec2 = point(line.b.x - line.a.x, line.b.y - line.a.y);

    double mod_vec1 = sqrt(vec1.x * vec1.x + vec1.y * vec1.y);
    double mod_vec2 = sqrt(vec2.x * vec2.x + vec2.y * vec2.y);
    double c = (vec1.x*vec2.x + vec1.y*vec2.y)/(mod_vec1*mod_vec2);
    double angle = acos((vec1.x*vec2.x + vec1.y*vec2.y)/(mod_vec1*mod_vec2));
    return angle;
}


