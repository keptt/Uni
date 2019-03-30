#include "reagent.h"

Reagent::Reagent(const std::string &name, float density):name(name), density(density)
{

}

Reagent::~Reagent()
{

}

void Reagent::intel() const
{
    print_name();
    print_obj_intel();
}

void Reagent::print_obj_intel() const
{
    printf("name - %s\ndensity - %f\n", name.c_str(), density);
}
