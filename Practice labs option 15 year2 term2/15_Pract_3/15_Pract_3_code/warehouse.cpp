#include "warehouse.h"

Warehouse::Warehouse(std::string address, std::string mission, std::string circs, double area)
    :Facility (address, mission, area), m_circs(circs)
{
}

std::string Warehouse::class_name() const
{
    return "Class name: Warehouse\n";
}

std::string Warehouse::obj_data() const
{
    std::string base_info(Facility::obj_data());

    char buffer[125];

    sprintf(buffer, "Circumstances: %s\n", m_circs.c_str());

    base_info += (std::string)buffer;

    return base_info;
}

Warehouse::~Warehouse()
{
}

