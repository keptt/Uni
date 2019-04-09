#include "container.h"
#pragma warning(disable:4996)
#define _CRT_SECURITY_NO_WARNINGS

container::container(std::string name, int size): name(name), size(size)
{

}

void container::print() const
{
    printf("Obj type: %s\n", get_typename().c_str());
    printf("%s", get_info().c_str());
}

std::string container::get_info() const
{
    char buff[101];
    sprintf(buff, "Name: %s\nSize: %d\n", name.c_str(), size);
    return  buff;
}

container::~container()
{

}
//std::string name;
//int size;
