#ifndef SETO_O_FLATS_H
#define SETO_O_FLATS_H
#include "flat.h"
#include "string.h"
class set_o_flats
{
private:
    flat *arr;
    unsigned int capacity;
    unsigned int size_arr;
	static void swap (int &a, int &b);
public:
    set_o_flats();

    void find_by_num_rooms(unsigned int num_rooms);
    void find_between_floors(int floor1, int floor2);
    void find_by_area_more_than(double area);
    void set_capacity(unsigned int capacity);
    void append(flat f);
    void clear();
//    const flat *get_flat_arr() const;
//    unsigned int get_size_arr() const;

    ~set_o_flats();
};

#endif // SETO_O_FLATS_H
