#include <iostream>
void display(int **arr, int lenght, int width);
void compute (int *arr[], int lenght, int width, int k);
void input(int **arr, int lenght, int width);

int main()
{
    int lenght(0);
    int width(0);
    std::cout << "Input lenght: ";
    std::cin >> lenght;
    std::cout << "Input width: ";
    std::cin >> width;
    int **arr = new int *[lenght];
    for (int i = 0; i < lenght; ++i)
    {
        arr[i] = new int[width];
    }

    int k(0);
    std::cout << "Input k-row: ";
    std::cin >> k;
    if (k >= lenght)
    {
        return 0;
    }
    std::cout << "///////////////////////////\n";
    input(arr, lenght, width);
    std::cout << "///////////////////////////\n";
    display(arr, lenght, width);
    std::cout << "///////////////////////////\n";
    compute(arr, lenght, width, k);
    std::cout << "///////////////////////////\n";
    display(arr, lenght, width);

    for (int i = 0; i < lenght; ++i)
    {
        delete []arr[i];
    }
    delete []arr;
    return 0;
}

void display(int **arr, int lenght, int width)
{
    for (int i = 0; i < lenght; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void input(int **arr, int lenght, int width)
{
    for (int i = 0; i < lenght; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            std::cout << "arr[" << i << "]" << "[" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }
}
void compute (int *arr[], int lenght, int width, int k)
{
      for (int j = 0; j < width; ++j)
      {
          arr[k][j] += arr[0][j];
      }
}
