#include <iostream>
#include "matrix.h"
#define ROWS 2
#define COLS 2
#define ROWSOVERFLOW 3

using namespace std;

int main()
{
    Matrix m1(2, 2);
    Matrix m2(2, 2);

    for (unsigned int i = 0; i < COLS; ++i)
    {
        for (unsigned int j = 0; j < ROWS; ++j)//i in for with j
        {
            int temp;
            std::cout << "Input value for 1st matrix: ";
            std::cin >> temp;
            m1.add(temp, i, j);
        }
    }

    m1.printOut();

    std::cout << "\n";

    for (unsigned int i = 0; i < COLS; ++i)
    {
        for (unsigned int j = 0; j < ROWS; ++j)//i in for with j
        {
            int temp;
            std::cout << "Input value for 2d matrix: ";
            std::cin >> temp;
            m2.add(temp, i, j);
        }
    }

    m2.printOut();

    Matrix m3(2, ROWSOVERFLOW);

    for (unsigned int i = 0; i < COLS; ++i)
    {
        for (unsigned int j = 0; j < ROWSOVERFLOW; ++j)//i in for with j
        {
            int temp;
            std::cout << "Input value for 3d matrix: ";
            std::cin >> temp;
            m3.add(temp, i, j);
        }
    }

    std::cout << "\n";

    m3.printOut();

    std::cout << "1st matrix + 2d matrix = ";
    try {
        m1 = m1 + m3;
    } catch (MatrixException &e) {
        std::cout << "\nError" << e.what() << std::endl;
    }

    return 0;
}
