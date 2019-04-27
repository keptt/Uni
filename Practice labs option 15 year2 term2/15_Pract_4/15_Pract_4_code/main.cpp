#include <iostream>
#include "decimal.h"

int main(){

    Decimal a(10, 12);
    Decimal b(11, 3);

    Decimal c = a/b;

    c.printOut();

    c = a*b;

    c.printOut();

    c = a+b;

    c.printOut();

    c = a-b;

    c.printOut();

	std::cin.get();

    return 0;
}
