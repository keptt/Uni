#ifndef FLAT_H
#define FLAT_H
#include <string>
#include <iostream>

class flat
{
private:
    std::string address_;
    int floor_;
    double S_;
    unsigned int num_rooms_;

public:
    flat( const char *address = "", int floor = 0,
         double S = 0, unsigned int num_rooms = 0);
    ~flat();

public:
    void set_floor(int floor);
    void set_S(double area);
    void set_num_rooms(unsigned int num_rooms);
    void set_address(const char *address);
    const std::string get_address() const;
    int get_floor() const;
    double get_S() const;
    unsigned int get_num_rooms() const;
    void print_flat();
};
#endif // FLAT_H
