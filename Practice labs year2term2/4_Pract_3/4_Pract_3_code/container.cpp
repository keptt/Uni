#include "container.h"

container::container(std::string name, int size): name(name), size(size)
{

}

void container::print() const
{
    printf("Obj type: %s\n", get_typename().c_str());
    printf("--Shared info:\n");
    printf("%s\n", get_base_info().c_str());
    printf("--Distinct info:\n");
    printf("%s\n", get_derived_info().c_str());
}

std::string container::get_base_info() const
{
    char buff[101];
    sprintf(buff, "Name: %s\nSize: %d", name.c_str(), size);
    return  buff;
}

container::~container()
{
}
