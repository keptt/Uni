#include "carbon.h"

Carbon::Carbon(std::string name, float density, std::string shape): Reagent(name, density)
{
    this->shape = shape;
}

void Carbon::print_obj_intel() const
{
    Reagent::print_obj_intel();
    printf("shape: %s\n", shape.c_str());
}

void Carbon::print_name() const
{
    printf("Carbon\n");
}
