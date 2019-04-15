#include "queue.h"

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

std::string queue::get_base_info() const
{
    return container::get_base_info();
}

std::string queue::get_derived_info() const
{
    char buffer[51];

    sprintf(buffer, "Head address: %p\nTail address: %p\n", head, tail);

    return buffer;
}

std::string queue::get_typename() const
{
    return "queue";
}

queue::~queue()
{
}
