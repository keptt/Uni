#include <iostream>

double Non_rec(double);
double Real_rec(double, double, double);

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cout << "Input n = ";
    std::cin >> n;
    if (n % 2 != 0 || !std::cin)
    {
        std::cout << "Bad input!" << std::endl;
        return 0;
    }
    std::cout << Non_rec(n) << std::endl;

    return 0;
}

double Non_rec(double n)
{
    double count = 0;
    double n_copy = n;
    return Real_rec(n, count, n_copy);

}
double Real_rec(double n, double count, double n_copy)
{
    if (count == n_copy)
        return 1;
    else
    {
        return ((n / (n + 1))*(n / (n - 1))*  Real_rec(n - 2, count + 2, n_copy));
    }
}
