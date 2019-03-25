#include "warehouse.h"

Warehouse::Warehouse(std::string address, std::string mission, std::string circs, double_t area)
    :Facility (address, mission, area), m_circs(circs)
{
}

Warehouse::~Warehouse()
{
}

void Warehouse::print_out() const
{
    std::cout << "\n\n" << "Class: Warehouse\n";
    Facility::print_out();
    std::cout << "Circumstances: " << m_circs << "\n\n";
}
