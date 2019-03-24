#include "queue.h"

queue::queue(std::string name, int *start_element) //: name(name)
{
    //container(name, size);
    this->name = name;
    this->size = 0;

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

void queue::get_info() const
{
    printf("\n");

    container::get_info();

    printf("\n");
}

queue::~queue()
{
}
