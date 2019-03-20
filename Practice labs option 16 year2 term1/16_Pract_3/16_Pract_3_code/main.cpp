#include <iostream>
#include <cmath>

int main ()
{
    double a = 5.1, b = -3.3, c = 2.4, d = 5.6;
    double result = (5 * log10(c) + exp(d)) / (sin(sqrt(a)) + cos(std::abs(b)));
    std::cout << "result = " << result << std::endl;

    return 0;
}

