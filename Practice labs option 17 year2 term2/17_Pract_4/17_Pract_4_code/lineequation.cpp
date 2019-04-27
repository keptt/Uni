#include "lineequation.h"
#include<stdio.h>
#include <math.h>

#define SMALL_FLOAT 0.00001f
#define FIRST_CONST_IF_SMTH_GOES_WRONG 1
#define SECOND_CONST_IF_SMTH_GOES_WRONG 2

LineEquation::LineEquation() {}

LineEquation::LineEquation(float k, float b): k(k), b(b){}

LineEquation::LineEquation(const LineEquation &line) {}

LineEquation::~LineEquation() {}

Point LineEquation::findIntersectionWithOx() const
{
    return {-(float)b/k, 0};
}

Point LineEquation::findIntersectionWithOy() const
{
    return {0, (float)b};
}

float LineEquation::get_k() const { return k; }

float LineEquation::get_b() const { return b; }

void LineEquation::set_k(float k) { this->k = k; }

void LineEquation::set_b(float b) { this->b = b; }

void LineEquation::printEquation() const
{
    (b > 0) ? printf("y = %fx + %f\n", k, b) : (b < 0) ? printf("y = %fx - %f\n", k, -b) : printf("y = %fx\n", k);
}

float LineEquation::operator%(const LineEquation &line)
{
    Point firstPoint1 = findIntersectionWithOx();
    Point firstPoint2 = findIntersectionWithOy();

    if (firstPoint1.x <= SMALL_FLOAT && firstPoint1.x >= -SMALL_FLOAT &&
            firstPoint1.y <= SMALL_FLOAT && firstPoint1.y >= -SMALL_FLOAT)
    {
        firstPoint1.x = FIRST_CONST_IF_SMTH_GOES_WRONG;
        firstPoint1.y = k*FIRST_CONST_IF_SMTH_GOES_WRONG + b;
    }
    if (firstPoint2.x <= SMALL_FLOAT && firstPoint2.x >= -SMALL_FLOAT &&
            firstPoint2.y <= SMALL_FLOAT && firstPoint2.y >= -SMALL_FLOAT)
    {
        firstPoint2.x = SECOND_CONST_IF_SMTH_GOES_WRONG;
        firstPoint2.y = k*SECOND_CONST_IF_SMTH_GOES_WRONG + b;
    }

    Point secondPoint1 = line.findIntersectionWithOx();
    Point secondPoint2 = line.findIntersectionWithOy();

    if (secondPoint1.x <= SMALL_FLOAT && secondPoint1.x >= -SMALL_FLOAT &&
            secondPoint1.y <= SMALL_FLOAT && secondPoint1.y >= -SMALL_FLOAT)
    {
        secondPoint1.x = FIRST_CONST_IF_SMTH_GOES_WRONG;
        secondPoint1.y = line.k*FIRST_CONST_IF_SMTH_GOES_WRONG + line.b;
    }
    if (secondPoint2.x <= SMALL_FLOAT && secondPoint2.x >= -SMALL_FLOAT &&
            secondPoint2.y <= SMALL_FLOAT && secondPoint2.y >= -SMALL_FLOAT)
    {
        secondPoint2.x = SECOND_CONST_IF_SMTH_GOES_WRONG;
        secondPoint2.y = line.k*SECOND_CONST_IF_SMTH_GOES_WRONG + line.b;
    }

    Point vec1 = {firstPoint2.x - firstPoint1.x, firstPoint2.y - firstPoint1.y};
    Point vec2 = {secondPoint2.x - secondPoint1.x, secondPoint2.y - secondPoint1.y};


    float one = fabs(vec1.x * vec2.x + vec1.y * vec2.y);
    float two = sqrt(vec1.x * vec1.x + vec1.y * vec1.y);
    float three = sqrt(vec2.x * vec2.x + vec2.y * vec2.y);

    float angle = fabs(vec1.x * vec2.x + vec1.y * vec2.y)/(sqrt(vec1.x * vec1.x + vec1.y * vec1.y)
                                                           *sqrt(vec2.x * vec2.x + vec2.y * vec2.y));

    angle = acos(angle);

    return angle;
}

bool LineEquation::operator&&(const LineEquation &line)
{
    return (k * line.k + 1 <= SMALL_FLOAT && k * line.k + 1 >= -SMALL_FLOAT);//same as k * line.k == -1
}
