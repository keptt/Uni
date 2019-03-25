#include "residentialbuilding.h"

ResidentialBuilding::ResidentialBuilding(std::string address, std::string mission, size_t apartm_count, double_t area)
                   : Facility(address, mission, area), m_apartm_count(apartm_count)
{
}

ResidentialBuilding::~ResidentialBuilding()
{
}

void ResidentialBuilding::print_out() const
{
    std::cout << "\n\n" << "Class: ResidentialBuilding\n";
    Facility::print_out();
    std::cout << "Number of apartments: " << m_apartm_count << "\n\n";
}
