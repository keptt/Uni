#include "queue.h"
#pragma warning(disable:4996)
#define _CRT_SECURITY_NO_WARNINGS

queue::queue(std::string name, void *start_element) : container(name, 0)
{
    //container::container(name, size);

    if (start_element)
    {
        this->head = start_element;
        size ++;
        this->tail = start_element;
    }
    else
    {
        head = nullptr;
        tail = nullptr;
    }


}

std::string queue::get_info() const
{
    std::string previnfo = container::get_info();

    char buffer[51];

    sprintf(buffer, "Head address: %p\nTail address: %p\n", head, tail);

    previnfo.append(buffer);

    return previnfo;
}

std::string queue::get_typename() const
{
    return "queue";
}

queue::~queue()
{
}
