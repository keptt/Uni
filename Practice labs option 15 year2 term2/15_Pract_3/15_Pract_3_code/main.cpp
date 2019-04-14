#include <iostream>
#include "facility.h"
#include "warehouse.h"
#include "residentialbuilding.h"
#include <algorithm>


int main()
{
    const size_t SIZE = 5;

    Facility **facility_arr = new Facility*[SIZE];
    facility_arr[0] = new Warehouse("56783", "edsfgkjfdsj", "good", 345.4);
    facility_arr[1] = new Warehouse("11111", "1111111111", "verygood", 1111);
    facility_arr[2] = new ResidentialBuilding("351234513", "wqereqwrt", 1124, 234.345);
    facility_arr[3] = new ResidentialBuilding("22222222", "smthsmth", 12.4, 123.5);
    facility_arr[4] = new Warehouse("00000", "000000", "0good", 555.9);

    std::random_shuffle(facility_arr, facility_arr + SIZE);

    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << "\n";
        facility_arr[i]->print_out();
        delete facility_arr[i];
        std::cout << "\n";
    }
    delete [] facility_arr;

    return 0;
}

