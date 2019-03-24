#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <stdio.h>

class container
{
protected:

    std::string name;
    int size;
public:

    virtual void get_info() const = 0;
    virtual ~container();//777
};

#endif // CONTAINER_H
