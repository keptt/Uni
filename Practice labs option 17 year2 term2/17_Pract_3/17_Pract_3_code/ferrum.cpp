#include "ferrum.h"


Ferrum::Ferrum(std::string name, float density, float prc_in_ore): Reagent(name, density)
{
    this->prc_in_ore = prc_in_ore;
}

void Ferrum::print_obj_intel() const
{
    Reagent::print_obj_intel();
    printf("shape: %f\n", prc_in_ore);
}

void Ferrum::print_name() const
{
    printf("Ferrum\n");
}

