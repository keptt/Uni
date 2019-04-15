#ifndef DECIMALREP_H
#define DECIMALREP_H
#include <iostream>

class DecimalRep
{
public:
    DecimalRep();
    DecimalRep(int nominator, int denomirntor);
    DecimalRep(const DecimalRep &);
    ~DecimalRep();
    void show() const;
    int get_nominator() const;
    int get_denominator() const;
    void set_nominator(int nominator);
    void set_denominator(int denominator);
    DecimalRep simplify();
    DecimalRep simplified() const;
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
