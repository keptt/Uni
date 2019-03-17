#include "set_o_flats.h"

void swap (int &a, int &b);

set_o_flats::set_o_flats(const flat *arr, const unsigned int size_arr):size_arr(size_arr){
    this->arr = new flat[size_arr];
    for (unsigned int i = 0; i < size_arr; ++i)
    {
        this->arr[i].set_floor(arr[i].get_floor());
        this->arr[i].set_num_rooms(arr[i].get_num_rooms());
        this->arr[i].set_S(arr[i].get_S());
        this->arr[i].set_address(arr[i].get_address());
    }
}

void set_o_flats::find_by_num_rooms(unsigned int num_rooms) const{
    std::cout << "\n\nKvartiri s " << num_rooms << " komnatami:\n\n";
    for (unsigned int i = 0; i < size_arr; ++i){
        if (arr[i].get_num_rooms() == num_rooms){
            print_flat(arr[i]);
             std::cout << "_________________________________\n";
        }
    }
}

void set_o_flats::find_between_floors(int floor1, int floor2) const{
    floor1 <= floor2 ? void() : swap(floor1, floor2);
    std::cout << "\n\nKvartiri mezhdu " << floor1 << " i " << floor2 << " etazhami:\n\n";
    for (unsigned int i = 0; i < size_arr; ++i){
        if (arr[i].get_floor() >= floor1 && arr[i].get_floor() <= floor2){
             print_flat(arr[i]);
             std::cout << "_________________________________\n";
        }
    }
}

void set_o_flats::find_by_area_more_than(double S) const{
    std::cout << "\n\nKvartiri s ploshiadiyu bolshe chem " << S << ":\n\n";
    for (unsigned int i = 0; i < size_arr; ++i){
        if (arr[i].get_S() > S){
            print_flat(arr[i]);
            std::cout << "_________________________________\n";
        }
    }
}

set_o_flats::~set_o_flats()
{
    delete [] arr;
}

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
