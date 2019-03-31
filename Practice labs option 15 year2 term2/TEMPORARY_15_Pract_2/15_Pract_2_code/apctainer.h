#pragma once
#include "apartments.h"

struct ApStruct
{
    char *address;
    int floor;
    size_t quantity_of_rooms;
    double area;
};

class ApCtainer
{
private:
    Apartments *m_ctainer;
    size_t m_size;
public:
    ApCtainer(ApStruct *ctainer, size_t size);
    void print_aps_by_rooms(size_t quantity_of_rooms) const;
    void print_aps_between_floors(int floor_a, int floor_b) const;
    void print_aps_ofless_area(double area) const;
    ~ApCtainer();
};

