#include <iostream>
template<typename T>
void sort(T *arr, int start, int end);
template<typename T>
void quick_sort(T **arr, size_t length, size_t width);
template<typename T>
void sort(T *arr, int start, int end);
template <typename T>
int partition(T *arr, int start, int end);
template <typename T>
void swap (T &a, T &b);
template<typename T>
void display(T **arr, size_t lenght, size_t width);
template<typename T>
void fill_arr(T **arr, size_t lenght, size_t width);


int main()
{
    size_t length(0);
    size_t width(0);
    std::cout << "input len: ";
    std::cin >> length;
    std::cout << "input wid: ";
    std::cin >> width;
    int **arr = new int*[length];
    for (size_t i = 0; i < width; ++i)
    {
        arr[i] = new int[width];
    }
    fill_arr(arr, length, width);
    display(arr, length, width);
    quick_sort(arr, length, width);
    display(arr, length, width);

    for (size_t i = 0; i < length; ++i)
    {
        delete []arr[i];
    }
    delete []arr;
    return 0;
}
template<typename T>
void display(T **arr, size_t lenght, size_t width)
{
    std::cout << "-------------------------------------\n";
    for (size_t i = 0; i < lenght; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
template<typename T>
void fill_arr(T **arr, size_t lenght, size_t width)//???
{
    for (size_t i = 0; i < lenght; ++i)
    {
        for(size_t j = 0; j < width; ++j)
        {
            arr[i][j] = rand()%15;
        }
    }
}
template<typename T>
void sort(T *arr, int start, int end)
{
    if (start < end)
    {
        int q = partition(arr, start, end);
        sort(arr, 0, q - 1);
        sort(arr, q + 1, end);
    }
}
template <typename T>
int partition(T *arr, int start, int end)
{
    T pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}
template<typename T>
void quick_sort(T **arr, size_t length, size_t width)
{
    for(size_t i = 0; i < length; ++i)
    {
        sort(arr[i], 0, width - 1);
    }
}
template <typename T>
void swap (T &a, T &b)
{
    T temp = b;
    b = a;
    a = temp;
}

