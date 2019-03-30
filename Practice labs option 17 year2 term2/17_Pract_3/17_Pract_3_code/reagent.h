#ifndef REAGENT_H
#define REAGENT_H
#include <string>

class Reagent
{
protected:
    std::string name;
    float density;
public:
    Reagent(const std::string &name, float density);
    virtual ~Reagent();
    void intel() const;
    virtual void print_obj_intel() const = 0;
    virtual void print_name() const = 0;
};

#endif // REAGENT_H
