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

    arr[0] = new queue("queueNotNULL", (void *)234234);

    arr[1] = new tree("treeNotNULL", (void *)99999);

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

    return 0;
}
