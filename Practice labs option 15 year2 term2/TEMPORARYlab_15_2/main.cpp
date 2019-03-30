#include <iostream>
#include "set_of_flats.h"

using namespace std;

void print_flat(const flat &f)
{
    cout << "Adres - " << f.get_address() << endl;
    cout << "Plosh'ya - " << f.get_S() << endl;
    cout << "Poverh - " << f.get_floor() << endl;
    cout << "K-st' kimnat - " << f.get_num_rooms() << endl;
}

void print_arr_o_flats(set_of_flats &arr)
{
    for (unsigned int i = 0; i < arr.get_size_arr(); ++i)
    {
        print_flat((arr.get_flat_arr())[i]);
        cout << "----------------------------------------\n";
    }
}

int main()
{
    flat arr[] = {flat("r456tg", 3, 534.0, 8)};//, flat("rtg", 23, 234.0, 3), flat("11111", 3, 134.0, 2)};
    set_of_flats set1(arr, 1, "set1");

//    print_arr_o_flats(set1);

//    set_o_flats set_temp("set_temp");

//    set_temp = set1.find_between_floors(20, 24);

//     print_arr_o_flats(set_temp);

//    std::cout << "____________________________________\n";
//    set_o_flats set2 (set_temp);

//    print_arr_o_flats(set2);
//    std::cout << "____________________________________\n";
    return 0;
}
