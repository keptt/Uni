#ifndef QUEUE_H
#define QUEUE_H
#include "container.h"

class queue : public container
{
    int *head;
    int *tail;
public:

    queue(std::string name = "queue", int *start_element = nullptr);
    virtual void get_info() const;
    virtual ~queue();
};

#endif // QUEUE_H
