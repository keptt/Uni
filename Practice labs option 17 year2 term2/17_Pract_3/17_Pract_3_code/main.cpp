#include <stdio.h>
#include "reagent.h"
#include "ferrum.h"
#include "carbon.h"
#define ARRSIZE 2

void free_ptrdouble_arr(Reagent **arr)
{
    for (int i = 0; i < ARRSIZE; i++)
    {
        delete arr[i];
    }

    delete[] arr;
}
void print_ptrdouble_arr(Reagent **arr)
{
    for (int i = 0; i < ARRSIZE; i++)
    {
        (*arr[i]).intel();
        printf("\n.............................................\n");
    }
}

int main()
{
    Reagent **array = new Reagent *[ARRSIZE];

    array[0] = new Carbon("C", 123, "rectangular");
    array[1] = new Ferrum("Fe", 234.3, 15.6);

    print_ptrdouble_arr(array);
    free_ptrdouble_arr(array);

    return 0;
}
