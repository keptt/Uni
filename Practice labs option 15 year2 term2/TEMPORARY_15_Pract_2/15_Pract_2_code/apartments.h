#pragma once
#include <iostream>
#include <cstring>

class Apartments
{
private:
    char *m_address;
    int m_floor;
    size_t m_quantity_of_rooms;
    double m_area;
public:
    Apartments(const char *address, const int floor, const size_t quantity_of_rooms,
               const double area);
    Apartments();
    void set_address(const char *address);
    void set_floor(const int floor);
    void set_quantity_of_rooms(const size_t quantity_of_rooms);
    void set_area(const double area);
    const char * get_address() const;
    int get_floor() const;
    double get_area() const;
    size_t get_quantity_of_rooms() const;
    void printout() const;
    ~Apartments();
};
