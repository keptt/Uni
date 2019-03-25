#include <iostream>
#include "set_o_flats.h"

using namespace std;

int main()
{
    set_o_flats set1;

    set1.append(flat("r456tg", 3, 534.0, 8));
    set1.append(flat("rtg", 23, 234.0, 3));
    set1.append(flat("11111", 43, 134.0, 3));
    set1.append(flat("3567tuyop8", 56, 245677, 2356));
    set1.append(flat("aaaaa", 2, 56, 1));

    set1.find_between_floors(2, 25);
    set1.find_by_num_rooms(3);
    set1.find_by_area_more_than(230);

    set1.clear();

    return 0;
}
