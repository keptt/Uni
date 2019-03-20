#include <iostream>

int main()
{
    int number(0);

    std::cout << "Input a number: ";
    std::cin >> number;

    switch (number / 10)
    {
    case 1:
        std::cout << "X";
        break;
    case 2:
        std::cout << "XX";
        break;
    case 3:
        std::cout << "XXX";
        break;
    default:
        std::cout << "Bad input [numbers shoud go from 1 to 39]" << std::endl;
    }
    switch (number % 10)
    {
    case 0:
        break;
    case 1:
        std::cout << "I" << std::endl;
        break;
    case 2:
        std::cout << "II" << std::endl;
        break;
    case 3:
        std::cout << "III" << std::endl;
        break;
    case 4:
        std::cout << "IV" << std::endl;
        break;
    case 5:
        std::cout << "V" << std::endl;
        break;
    case 6:
        std::cout << "VI" << std::endl;
        break;
    case 7:
        std::cout << "VII" << std::endl;
        break;
    case 8:
        std::cout << "VIII" << std::endl;
        break;
    case 9:
        std::cout << "IX" << std::endl;
        break;
    }
    return 0;
}
