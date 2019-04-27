#pragma once

#include <iostream>

class Decimal
{
private:
    int numerator;
    int denominator;
    bool invalid;

public:
    Decimal(int, int);
    Decimal(const Decimal &) = default;

    Decimal &easeUp();
    void printOut() const;

    Decimal operator+(Decimal &);
    Decimal operator-(Decimal &);
    Decimal operator/(Decimal &);
    Decimal operator*(Decimal &);

    ~Decimal() = default;
};
