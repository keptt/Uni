#include "decimalrep.h"

DecimalRep::DecimalRep():nominator(0), denominator(1){
}

DecimalRep::DecimalRep(int nominator, int denominator){
    if (!denominator){
        this->denominator = 1; this->nominator = nominator;
    }
    else if(nominator < 0 && denominator < 0 ){
        this->denominator = -denominator; this->nominator = -nominator;
    }
    else{
        this->denominator = denominator; this->nominator = nominator;
    }
}

DecimalRep::DecimalRep(const DecimalRep &alien):nominator(alien.nominator), denominator(alien.denominator){
}

DecimalRep::~DecimalRep(){
}

void DecimalRep::show() const{
    if (denominator < 0 || nominator < 0)
        std::cout << "-" << abs(nominator) << "/" << abs(denominator);
    else
        std::cout << nominator << "/" << denominator;
}

int DecimalRep::get_nominator() const{
    return nominator;
}

int DecimalRep::get_denominator() const{
    return denominator;
}

void DecimalRep::set_nominator(int nominator){
    this->nominator = nominator;
}

void DecimalRep::set_denominator(int denominator){
    this->denominator = denominator;
}

DecimalRep DecimalRep::simplify(){
    int end_limit = abs(nominator) < abs(denominator) ? abs(nominator) : abs(denominator);
    for(int i = 2; i <= end_limit; ++i){
        if (nominator % i == 0 &&  denominator % i == 0){
            nominator /= i;
            denominator /= i;
            i = 2 - 1;
        }
    }
    return *this;
}

DecimalRep DecimalRep::simplified() const{
    DecimalRep temp(*this);
    return temp.simplify();
}

void DecimalRep::toSameBase(DecimalRep &rep){
    int tempDen = denominator;

    denominator *= rep.denominator;
    nominator *= rep.denominator;

    rep.denominator *= tempDen;
    rep.nominator *= tempDen;
}

DecimalRep DecimalRep::operator+(DecimalRep rep){
    DecimalRep firstDecimal(*this);
    DecimalRep secondDecimal(rep);

    if (firstDecimal.denominator != secondDecimal.denominator)
        firstDecimal.toSameBase(secondDecimal);

    DecimalRep result(firstDecimal.nominator + secondDecimal.nominator, firstDecimal.denominator);

    return result.simplify();
}

DecimalRep DecimalRep::operator-(DecimalRep rep){
    DecimalRep firstDecimal(*this);
    DecimalRep secondDecimal(rep);

    if (firstDecimal.denominator != secondDecimal.denominator)
        firstDecimal.toSameBase(secondDecimal);

    DecimalRep result(firstDecimal.nominator - secondDecimal.nominator, firstDecimal.denominator);

    return result.simplify();
}

DecimalRep DecimalRep::operator*(DecimalRep rep){
    DecimalRep result(nominator * rep.nominator, denominator * rep.denominator);

    return result.simplify();
}

DecimalRep DecimalRep::operator/(DecimalRep rep){
    DecimalRep result(nominator * rep.denominator, denominator * rep.nominator);

    return result.simplify();
}

std::ostream &operator<<(std::ostream &out, DecimalRep rep){
    if (rep.denominator < 0 || rep.nominator < 0)
        out << "-" << abs(rep.nominator) << "/" << abs(rep.denominator);
    else
        out << rep.nominator << "/" << rep.denominator;

    return out;
}


