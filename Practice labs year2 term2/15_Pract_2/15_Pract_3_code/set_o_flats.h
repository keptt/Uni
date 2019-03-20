#ifndef SETO_O_FLATS_H
#define SETO_O_FLATS_H
#include "flat.h"
#include "string.h"
class set_o_flats
{
private:
    flat *arr;
    unsigned int size_arr;
public:
    set_o_flats(const flat *, const unsigned int);

    void find_by_num_rooms(unsigned int num_rooms) const;
    void find_between_floors(int floor1, int floor2) const;
    void find_by_area_more_than(double area) const;

    ~set_o_flats();
};

#endif // SETO_O_FLATS_H
