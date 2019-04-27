#include "decimal.h"

Decimal::Decimal(int numeratorC, int denominatorC){
    invalid = false;
    if (numeratorC < 0 && denominatorC < 0){
        denominatorC *= (-1);
        numeratorC *= (-1);
    }
    else if(denominatorC < 0){
        numeratorC *= (-1);
        denominatorC *= (-1);
    }
    else if(denominatorC == 0){
        denominatorC = 1;
        invalid = true;
    }
    numerator = numeratorC;
    denominator = denominatorC;
}

Decimal &Decimal::easeUp(){
    if (numerator == 0){
        denominator = 1;
        return *this;
    }
    for (int i = 2; i < abs(numerator) && i < denominator; ++i){
        if (numerator%i == 0 && denominator%i == 0){
            numerator /= i;
            denominator /= i;
            i = 2;
        }
    }
    return *this;
}

void Decimal::printOut() const{
    std::cout << numerator << "/" << denominator << std::endl;
}

Decimal Decimal::operator+(Decimal &alien){
    if (denominator != alien.denominator){
        int temp = denominator;
        denominator *= alien.denominator;
        numerator *= alien.denominator;
        alien.numerator *= temp;
    }
    return Decimal(numerator + alien.numerator, denominator).easeUp();
}

Decimal Decimal::operator-(Decimal &alien){
    if (denominator != alien.denominator){
        int temp = denominator;
        denominator *= alien.denominator;
        numerator *= alien.denominator;
        alien.numerator *= temp;
    }
    return Decimal(numerator - alien.numerator, denominator).easeUp();
}

Decimal Decimal::operator/(Decimal &alien){
    return Decimal(numerator * alien.denominator, denominator * alien.numerator).easeUp();
}
//3 in 10 people
//stared, gazed, glance at
//peer through
//tigth deadline
Decimal Decimal::operator*(Decimal &alien){
    return Decimal(numerator * alien.numerator, denominator * alien.denominator).easeUp();
}
