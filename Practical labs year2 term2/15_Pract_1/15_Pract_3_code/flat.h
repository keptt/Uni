#ifndef FLAT_H
#define FLAT_H
#include <cstring>
#include <iostream>
class flat
{
private:
    char *address_;
    int floor_;
    double S_;
    unsigned int num_rooms_;

public:
    flat( const char *address = const_cast<char*>(""), int floor = 0,
         double S = 0, unsigned int num_rooms = 0);
    ~flat();
public:
	void set_address(const char *address);
    void set_floor(int floor);
	void set_num_rooms(unsigned int num_rooms);
    void set_S(double area);
    
    const char *get_address() const;
    int get_floor() const;
	unsigned int get_num_rooms() const;
    double get_S() const;   
};
#endif // FLAT_H
