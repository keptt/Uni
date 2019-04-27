#include "lineequation.h"
#include <stdio.h>

int main()
{
    LineEquation l1(3, 0);
    LineEquation l2(-1/(float)3, 0);

    printf("l1 line equation: ");
    l1.printEquation();
    printf("l2 line equation: ");
    l2.printEquation();

    printf("l1 intersection point with Ox: (%.6f, %.6f)\n", l1.findIntersectionWithOx());
    printf("l1 intersection point with Oy: (%.6f, %.6f)\n", l1.findIntersectionWithOy());

    printf("l2 intersection point with Ox: (%.6f, %.6f)\n", l2.findIntersectionWithOx());
    printf("l2 intersection point with Oy: (%.6f, %.6f)\n", l2.findIntersectionWithOy());

    printf("is perpendicular: %d\n", l1 && l2);

    printf("angle between lines equals %.6f radians\n", l1 % l2);

    return 0;
}
