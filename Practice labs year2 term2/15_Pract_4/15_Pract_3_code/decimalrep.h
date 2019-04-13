#ifndef DECIMALREP_H
#define DECIMALREP_H
#include <iostream>

class DecimalRep
{
public:
    DecimalRep();
    DecimalRep(int deniminator, int denomirntor);
    void show() const;
    DecimalRep simplify();
    DecimalRep simplified();
    DecimalRep operator+(DecimalRep rep);
    DecimalRep operator-(DecimalRep rep);
    DecimalRep operator*(DecimalRep rep);
    DecimalRep operator/(DecimalRep rep);
    friend std::ostream &operator<<(std::ostream &out, const DecimalRep rep);
private:
    int nominator;
    int denominator;
    void toSameBase(DecimalRep &rep);
};

#endif // DECIMALREP_H
