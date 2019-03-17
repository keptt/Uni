#include <iostream>
void display(int arr[][5], size_t lenght, size_t width);
void input(int arr[][5], size_t lenght, size_t width);
void compute(int arr[][5], size_t lenght, size_t width, size_t k);

int main()
{
    const static size_t len(5);
    const static size_t wid(5);
    size_t k(0);
    std::cout << "Input k-row: ";
    std::cin >> k;
    if (k >= len)
    {
        return 0;
    }
    int arr[len][wid];
    std::cout << "///////////////////////////\n";
    input(arr, len, wid);
    std::cout << "///////////////////////////\n";
    display(arr, len, wid);
    std::cout << "///////////////////////////\n";
    compute(arr, len, wid, k);
    std::cout << "///////////////////////////\n";
    display(arr, len, wid);
    std::cout << "///////////////////////////\n";
    return 0;
}

void display(int arr[][5], size_t lenght, size_t width)
{
    for (size_t i = 0; i < lenght; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void input(int arr[][5], size_t lenght, size_t width)
{
    for (size_t i = 0; i < lenght; ++i)
    {
        for(size_t j = 0; j < width; ++j)
        {
            std::cout << "arr[" << i << "]" << "[" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }
}

void compute(int arr[][5], size_t lenght, size_t width,size_t k)
{
    for (size_t j = 0; j < width; ++j)
    {
        arr[k][j] += arr[0][j];
    }
}
