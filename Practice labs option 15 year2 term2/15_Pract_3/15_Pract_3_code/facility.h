#pragma once
#include <string>
#include <iostream>
#include <cmath>

class Facility
{
public:
    Facility(std::string address = "", std::string mission = "", double area = 0);
    void print_out() const;
    virtual std::string class_name()const = 0 ;
    virtual std::string obj_data() const = 0;
    virtual ~Facility() = 0;
protected:
    std::string m_address, m_mission;
    double m_area;
};

