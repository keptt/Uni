#include "flat.h"

using namespace std;

flat::flat(const char *address, int floor, double S, unsigned int num_rooms) :
    address_(), floor_(floor), S_(S), num_rooms_(num_rooms)
{
    address_ = new char[strlen(address)+1];
    strcpy(address_, address);
}

//flat::flat(const flat &other):
//    address_(), floor_(other.floor_), S_(other.S_), num_rooms_(other.num_rooms_)
//{
//    address_ = new char[strlen(other.address_)+1];
//    strcpy(address_, other.address_);
//}

flat::~flat()
{
    std::cout << "flat destructor invoked\n";
    delete[] address_;
}

flat flat::operator=(const flat &other)
{
    delete[] address_;
    address_ = new char[strlen(other.address_)+1];
    strcpy(address_, other.address_);
    floor_ = other.floor_;
    S_ = other.S_;
    num_rooms_ = other.num_rooms_;

    return *this;
}

void flat::set_floor(int floor)
{
    floor_ = floor;
}
void flat::set_S(double S)
{
    S_ = S;
}
void flat::set_num_rooms(unsigned int num_rooms)
{
    num_rooms_ = num_rooms;
}
void flat::set_address(const char *address)
{
    delete[] address_;
    address_ = new char[strlen(address)+1];
    strcpy(address_, address);
}

const char * flat::get_address() const
{
    return address_;
}
int flat::get_floor() const
{
    return floor_;
}
double flat::get_S() const
{
    return S_;
}
unsigned int flat::get_num_rooms() const
{
    return num_rooms_;
}
