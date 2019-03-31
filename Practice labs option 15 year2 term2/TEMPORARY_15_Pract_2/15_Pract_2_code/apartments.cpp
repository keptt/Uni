#include "apartments.h"

Apartments::Apartments(const char *address, const int floor, const size_t quantity_of_rooms,
                       const double area):m_address(new char [strlen(address)+1]),
m_floor(floor), m_quantity_of_rooms(quantity_of_rooms), m_area(area)
{
    strcpy(m_address, address);
}

Apartments::Apartments() :m_address(nullptr), m_floor(0), m_quantity_of_rooms(0),
                          m_area(0)
{
}

Apartments::~Apartments()
{
    delete[] m_address;
}

void Apartments::set_address(const char *address)
{
    delete[] m_address;
    m_address = new char[strlen(address) + 1];
    strcpy(m_address, address);
}

void Apartments::set_floor(const int floor)
{
    m_floor = floor;
}

void Apartments::set_quantity_of_rooms(const size_t quantity_of_rooms)
{
    m_quantity_of_rooms = quantity_of_rooms;
}

void Apartments::set_area(const double area)
{
    m_area = area;
}

const char *Apartments::get_address() const
{

       return (!m_address) ? "" : m_address;
}

int Apartments::get_floor() const
{
    return m_floor;
}

double Apartments::get_area() const
{
    return m_area;
}

size_t Apartments::get_quantity_of_rooms() const
{
    return m_quantity_of_rooms;
}

void Apartments::printout() const
{
    std::cout << "Address: " << this->get_address() << std::endl
              << "Floor: " << this->get_floor() << std::endl
              << "Quantity of rooms: " << this->get_quantity_of_rooms() << std::endl
              << "Area: " << this->get_area() << std::endl;
}
