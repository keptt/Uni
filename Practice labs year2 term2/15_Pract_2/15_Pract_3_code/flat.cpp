#include "flat.h"

using namespace std;

flat::flat(const char *address, int floor, double S, unsigned int num_rooms) :
    address_(), floor_(floor), S_(S), num_rooms_(num_rooms)
{
    address_ = new char[strlen(address)+1];
    strcpy(address_, address);
}

flat::~flat()
{
    delete[] address_;
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

void print_flat(const flat &f)
{
    cout << "Adres - " << f.get_address() << endl;
    cout << "Plosh'ya - " << f.get_S() << endl;
    cout << "Poverh - " << f.get_floor() << endl;
    cout << "K-st' kimnat - " << f.get_num_rooms() << endl;
}
