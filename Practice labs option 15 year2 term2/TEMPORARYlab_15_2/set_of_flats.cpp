#include "set_of_flats.h"
void swap (int &a, int &b);
struct a
{
    //double f;
    int p;
};
set_of_flats::set_of_flats(const flat *arr/* = nullptr*/, const unsigned int size_arr, std::string name):size_arr(size_arr){
    this->arr = new flat[size_arr];
    this->name = name;
//    std::cout << "size: " <<  sizeof(arr[0].get_S()) << std::endl;
//    std::cout << "size: " <<  sizeof(arr[0].get_address()) << std::endl;
//    std::cout << "size: " <<  sizeof(arr[0].get_floor()) << std::endl;
//    std::cout << "size: " <<  sizeof(arr[0].get_num_rooms()) << std::endl;
//    std::cout << "size: " <<  sizeof(arr[0])*(size_arr) << std::endl;
//    std::cout << "size: " <<  sizeof(a) << std::endl;
//    std::cout << "size: " <<  sizeof(flat) << std::endl;
    std::cout << this->name << " CTOR INVOKED: " << std::endl;
    memcpy(this->arr, arr, sizeof(arr[0])*(size_arr));
   // std::copy(arr, arr+size_arr, this->arr);
}

set_of_flats::set_of_flats(std::string name): arr(nullptr), size_arr(0){
    this->name = name;
    std::cout << this->name << " DEF CTOR INVOKED: " << std::endl;
}

set_of_flats::set_of_flats(const set_of_flats &other_set):size_arr(other_set.get_size_arr()){
    std::cout << other_set.name << " to " << name << " CPY CTOR INVOKED: " << std::endl;
    arr = new flat[size_arr];
    memcpy(arr, other_set.get_flat_arr(), sizeof(arr[0])*(size_arr));
    //std::copy(other_set.get_flat_arr(), other_set.get_flat_arr()+size_arr, arr);
}

set_of_flats set_of_flats::operator=(const set_of_flats &other_set){
    delete[] arr;
    std::cout << "= INVOKED: " << std::endl;
    size_arr = other_set.size_arr;
    arr = new flat[size_arr];
    memcpy(arr, other_set.get_flat_arr(), sizeof(arr[0])*(size_arr));
    //std::copy(other_set.get_flat_arr(), other_set.get_flat_arr()+size_arr, arr);
    return *this;
}

set_of_flats *set_of_flats::find_by_num_rooms(unsigned int num_rooms){//do not forget to delete after usage
    unsigned int count = 0;
    for (unsigned int i = 0; i < size_arr; ++i){
        if (arr[i].get_num_rooms() == num_rooms){
            ++count;
        }
    }
    flat *flats_arr = new flat[count];
    for (unsigned int i = 0, j = 0; i < size_arr; ++i){
        if (arr[i].get_num_rooms() == num_rooms){
            flats_arr[j] = arr[i];
            ++j;
        }
    }
    set_of_flats *general_obj_arr = new set_of_flats(flats_arr, count);
    delete[] flats_arr;
    return general_obj_arr;
}

set_of_flats set_of_flats::find_between_floors(int floor1, int floor2){
    unsigned int count = 0;
    floor1 <= floor2 ? void() : swap(floor1, floor2);
//    for (unsigned int i = 0; i < size_arr; ++i){
//        if (arr[i].get_floor() >= floor1 && arr[i].get_floor() <= floor2){
//            ++count;
//        }
//    }
    count = static_cast<unsigned int>(
            std::count_if(arr, arr+size_arr, [floor1, floor2](flat f){return f.get_floor() >= floor1 && f.get_floor() <= floor2;}));

    flat *flats_arr = new flat[count];
    for (unsigned int i = 0, j = 0; i < size_arr; ++i){
        if (arr[i].get_floor() >= floor1 && arr[i].get_floor() <= floor2){
            flats_arr[j] = arr[i];
            ++j;
        }
    }
    std::cout << "flat arr::::: ";//loop for debagging purposes
    for (unsigned int i = 0, j = 0; i < count; ++i)
    {
        std::cout << flats_arr[i].get_floor() << std::endl;
    }
    std::cout << "::::::::::::::::::::::\n ";
    set_of_flats general_obj_arr(flats_arr, count, "find_between_floors"); //= new set_o_flats(flats_arr, count);
    //delete[] flats_arr;
    return general_obj_arr;
}

set_of_flats *set_of_flats::find_by_area_more_than(double S){
    unsigned int count = 0;
    for (unsigned int i = 0; i < size_arr; ++i){
        if (arr[i].get_S() > S){
            ++count;
        }
    }
    flat *flats_arr = new flat[count];
    for (unsigned int i = 0, j = 0; i < size_arr; ++i){
        if (arr[i].get_S() > S){
            flats_arr[j] = arr[i];
            ++j;
        }
    }
    set_of_flats *general_obj_arr = new set_of_flats(flats_arr, count);
    delete[] flats_arr;
    return general_obj_arr;
}

const flat *set_of_flats::get_flat_arr() const
{
    return arr;
}

unsigned int set_of_flats::get_size_arr() const
{
    return size_arr;
}

set_of_flats::~set_of_flats()
{
    std::cout << name << " DTOR INVOKED: " << std::endl;
    delete [] arr;
}

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
