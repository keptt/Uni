#ifndef QUEUE_H
#define QUEUE_H
#include "container.h"

class queue : public container
{
    void *head;
    void *tail;
public:

    queue(std::string name = "queue", void *start_element = nullptr);
    virtual std::string get_info() const;
    virtual std::string get_typename() const;
    virtual ~queue();
};

#endif // QUEUE_H
