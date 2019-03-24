#include "container.h"

void container::get_info()  const
{
    printf("name: %s\n", name.c_str());
    printf("size: %d\n", size);
}

container::~container()
{

}
