#ifndef FERRUM_H
#define FERRUM_H
#include "reagent.h"

class Ferrum: public Reagent
{
    float prc_in_ore;
public:
    Ferrum(std::string name, float density, float prc_in_ore);
    void print_obj_intel() const;
    void print_name() const;
};

#endif // FERRUM_H
