#include <iostream>
#include "container.h"
#include "queue.h"
#include "tree.h"
#define ARRSIZE 2
using namespace std;

int main()
{
    queue q;
    tree t;

    container **arr = new container *[ARRSIZE];

    arr[0] = new queue();

    arr[1] = new tree();

    for (int i = 0; i < ARRSIZE; i++)
    {
        printf("..............................................\n");
        arr[i]->print();
        printf("..............................................\n");
    }

    for (int i = 0; i < ARRSIZE; i++)
    {
        delete arr[i];
    }
    delete [] arr;

	getchar();

    return 0;
}
