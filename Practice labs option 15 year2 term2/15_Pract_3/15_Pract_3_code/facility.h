#ifndef FACILITY_H
#define FACILITY_H
#include <string>
#include <iostream>
#include <cmath>

class Facility
{
public:
    Facility(std::string address = "", std::string mission = "", double_t area = 0);
    virtual void print_out() const = 0;
    virtual ~Facility() = 0;
protected:
    std::string m_address, m_mission;
    double_t m_area;
};

#endif // FACILITY_H
