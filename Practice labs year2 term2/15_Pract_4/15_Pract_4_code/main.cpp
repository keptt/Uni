#include <iostream>
#include "decimalrep.h"

using namespace std;

int main()
{

    int nominator, denominator;
    cout << "Input nominator of the 1st decimal: ";
    cin >> nominator;
    cout << "Input denominator of the 1st decimal: ";
    cin >> denominator;

    DecimalRep d1(nominator, denominator);

    cout << "Input nominator of the 2d decimal: ";
    cin >> nominator;
    cout << "Input denominator of the 2d decimal: ";
    cin >> denominator;

    DecimalRep d2(nominator, denominator);

    cout << "\n----------------------ADDITION--------------------------\n";
    cout << d1 << " + " << d2 << " = " << (d1 + d2);
    cout << "\n----------------------SUBSTRUCTION-----------------------\n";
    cout << d1 << " - " << d2 << " = " << (d1 - d2);
    cout << "\n----------------------MULTIPLICATION----------------------\n";
    cout << d1 << " * " << d2 << " = " << (d1 * d2);
    cout << "\n----------------------DIVISION----------------------------\n";
    cout << d1 << " / " << d2 << " = " << (d1 / d2) << std::endl;

    return 0;
}
