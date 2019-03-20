#include "pch.h"
#include <iostream>


int main()
{

    int quantity(0);
    std::cout << "Введіть к-сть студентів: ";
    std::cin >> quantity;

    while (quantity > 30)
    {
        std::cout << "Максимальна кількість студентів у группі - 30" << std::endl;
        std::cout << "Введіть кількість ще раз: ";
        std::cin >> quantity;
    }

    switch (quantity >= 11 && quantity <= 14 ? 0 : quantity % 10)
    {
    case 1:
        std::cout << "У нашій группі " << quantity << " студент";
        break;
    case 2:
    case 3:
    case 4:
        std::cout << "У нашій группі " << quantity << " студенти";
        break;
    default:
        std::cout << "У нашій группі " << quantity << " студентів";
        break;
    }



    return 0;
}
