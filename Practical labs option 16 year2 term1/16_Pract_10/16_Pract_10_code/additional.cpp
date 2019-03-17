#include <ctime>
#include <algorithm>
#include <iostream>

void fill_arr(int *arr,size_t size);
void display(int *arr,size_t size);
int compute(int *arr,size_t size, int seek_it);

int main()
{
    srand(time(NULL));

    size_t size = 1+ rand()%15;

    int *arr = new int[size];

    fill_arr(arr, size);
    display(arr, size);

    std::sort(arr, arr+size);

    display(arr,size);

    int seek_it (0);

    std::cout << "Input x: ";
    std::cin >> seek_it;

    std::cout << "Result: " << compute(arr, size, seek_it) << std::endl;

    delete []arr;

    return 0;
}

void fill_arr(int *arr,size_t size)
{
    for (size_t i = 0;  i < size; ++i)
    {
        arr[i] = rand()%15;
    }
}
void display(int *arr,size_t size)
{
    std::cout << "------------------------------------\n";
    for (size_t i = 0;  i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
int compute(int *arr, size_t size, int seek_it)
{
    for (int i = 0; i < (int)size - 1; ++i)
    {
        if (*(arr + i) < seek_it && seek_it < *(arr + (i+1)))
        {
            return i + 1;
        }
    }
    return -1;
}
