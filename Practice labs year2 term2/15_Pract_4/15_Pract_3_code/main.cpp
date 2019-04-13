#include <iostream>
#include "decimalrep.h"

using namespace std;

int main()
{
    DecimalRep d0(0, 0);

    DecimalRep d1;

    DecimalRep d2(12, 14);

    DecimalRep d3(5, 6);

    DecimalRep d4(4, 16);

    DecimalRep res = d2 / d3;

    std::cout << d2 << " / " << d3 << " = " << res << "\n";

    res = d2 * d3;

    std::cout << d2 << " * " << d3 << " = " << res << "\n";

    res = d2 + d3;

    std::cout << d2 << " + " << d3 << " = " << res << "\n";

    res = d2 - d3;

    std::cout << d2 << " - " << d3 << " = " << res << "\n";

    std::cout << "d2 = " << d2 <<  " simplified d2 = " << d2.simplified() << "\n";

    std::cout << "d3 = " << d3 << " simplified d3 = " << d3.simplify() << "\n";

     std::cout << "d4 = " << d4 << " simplified d4 = " << d4.simplified() << "\n";

    return 0;
}
