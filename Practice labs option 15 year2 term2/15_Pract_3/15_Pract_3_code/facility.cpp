#include "facility.h"

Facility::Facility(std::string address, std::string mission, double area)
    : m_address(address), m_mission(mission), m_area(area)
{
}

Facility::~Facility()
{
}

void Facility::print_out() const
{
    std::cout << class_name();
    std::cout << obj_data();
}

std::string Facility::obj_data() const
{
    char buffer[57];
    sprintf(buffer, "address: %s\nmission: %s\narea: %f\n", m_address.c_str(),
            m_mission.c_str(), m_area);

    return buffer;
}


