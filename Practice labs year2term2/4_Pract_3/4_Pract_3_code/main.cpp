#include <iostream>
#include "container.h"
#include "queue.h"
#include "tree.h"
using namespace std;

int main()
{
    queue q;
    tree t;

    container *obj = &q;

    obj->get_info();

    obj = &t;

    obj->get_info();

    return 0;
}
