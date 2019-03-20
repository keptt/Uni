#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cout << "enter n = ";
    std::cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (pow(i, 2) + pow(j, 2) == n)
            {
                std::cout << "Pair is " << i << " and " << j << std::endl;
            }
        }
    }

    return 0;
}
