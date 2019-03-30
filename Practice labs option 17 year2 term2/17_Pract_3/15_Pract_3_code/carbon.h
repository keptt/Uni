#ifndef CARBON_H
#define CARBON_H
#include "reagent.h"

class Carbon: public Reagent
{
    std::string shape;
public:
    Carbon(std::string name, float density, std::string shape);
    void print_obj_intel() const;
    void print_name() const;
};

#endif // CARBON_H
