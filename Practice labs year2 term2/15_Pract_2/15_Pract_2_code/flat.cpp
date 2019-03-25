#include "flat.h"

using namespace std;

flat::flat(const char *address, int floor, double S, unsigned int num_rooms) :
    address_(address), floor_(floor), S_(S), num_rooms_(num_rooms)
{}

flat::~flat()
{}

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
    address_ = address;
}

const std::string flat::get_address() const
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

void flat::print_flat()
{
    cout << "Adres - " << address_ << endl;
    cout << "Plosh'ya - " << S_ << endl;
    cout << "Poverh - " << floor_ << endl;
    cout << "K-st' kimnat - " << num_rooms_ << endl;
}
