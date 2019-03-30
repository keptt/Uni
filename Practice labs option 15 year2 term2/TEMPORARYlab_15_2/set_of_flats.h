#ifndef SETO_O_FLATS_H
#define SETO_O_FLATS_H
#include "flat.h"
#include "string.h"
#include <algorithm>

class set_of_flats
{
private:
    flat *arr;
    unsigned int size_arr;
    std::string name;
public:
    set_of_flats(const flat *, const unsigned int, std::string name = "none");
    set_of_flats(std::string name = "none");
    set_of_flats(const set_of_flats&);

    set_of_flats operator=(const set_of_flats &);

    set_of_flats *find_by_num_rooms(unsigned int num_rooms);
    set_of_flats find_between_floors(int floor1, int floor2);
    set_of_flats *find_by_area_more_than(double area);
    const flat *get_flat_arr() const;
    unsigned int get_size_arr() const;

    ~set_of_flats();
};

#endif // SETO_O_FLATS_H
