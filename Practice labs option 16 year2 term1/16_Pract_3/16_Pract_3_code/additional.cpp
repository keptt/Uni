#include <stdio.h>
#include <cmath>

int main(int argc, char const *argv[])
{
    double a (5.1), b (-3.3), c (2.4), d (5.6);
    printf("Enter a, b, c, d: ");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double result = (5 * log10(c) + exp(d))/(sin(sqrt(a))+ cos(std::abs(b)));
    printf("Outcome: %lf", result);

    return 0;
}