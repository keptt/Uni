#include "facility.h"

Facility::Facility(std::string address, std::string mission, double_t area)
    : m_address(address), m_mission(mission), m_area(area)
{
}

Facility::~Facility()
{
}

void Facility::print_out() const
{
    std::cout << "Address: " << m_address << std::endl
    << "Mission: " << m_mission << std::endl
    << "Area: " << m_area << std::endl;
}

