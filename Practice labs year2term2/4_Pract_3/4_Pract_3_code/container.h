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

    container(std::string name, int size);
    void print() const;
    virtual std::string get_base_info() const = 0;
    virtual std::string get_derived_info() const = 0;
    virtual std::string get_typename() const = 0;
    virtual ~container();
};

#endif // CONTAINER_H
