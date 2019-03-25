#include "set_o_flats.h"

set_o_flats::set_o_flats():arr(nullptr), size_arr(0), capacity(0){
}

void set_o_flats::find_by_num_rooms(unsigned int num_rooms){
    std::cout << "\n\nKvartiri s " << num_rooms << " komnatami:\n\n";
    for (unsigned int i = 0; i < size_arr; ++i){
        if (arr[i].get_num_rooms() == num_rooms){
            arr[i].print_flat();
             std::cout << "_________________________________\n";
        }
    }
}

void set_o_flats::find_between_floors(int floor1, int floor2){
    floor1 <= floor2 ? void() : swap(floor1, floor2);
    std::cout << "\n\nKvartiri mezhdu " << floor1 << " i " << floor2 << " etazhami:\n\n";
    for (unsigned int i = 0; i < size_arr; ++i){
        if (arr[i].get_floor() >= floor1 && arr[i].get_floor() <= floor2){
             arr[i].print_flat();
             std::cout << "_________________________________\n";
        }
    }
}

void set_o_flats::find_by_area_more_than(double S){
    std::cout << "\n\nKvartiri s ploshiadiyu bolshe chem " << S << ":\n\n";
    for (unsigned int i = 0; i < size_arr; ++i){
        if (arr[i].get_S() > S){
            arr[i].print_flat();
            std::cout << "_________________________________\n";
        }
    }
}

void set_o_flats::set_capacity(unsigned int capacity){
    this->capacity = capacity;
}

void set_o_flats::append(flat f){
    if (capacity < size_arr + 1){
        capacity = (unsigned int)((size_arr + 1)*1.5);

        flat *temp = new flat[capacity];
        if (arr){
            std::copy(arr, arr + size_arr, temp);
        }
        temp[size_arr] = f;
        arr = temp;
        size_arr++;
    }else{
        arr[size_arr] = f;
        size_arr++;
    }
}

set_o_flats::~set_o_flats(){
    delete [] arr;
}

void set_o_flats::swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void set_o_flats::clear(){
    delete [] arr;
    arr = nullptr;
    size_arr = 0;
    capacity = 0;
}
