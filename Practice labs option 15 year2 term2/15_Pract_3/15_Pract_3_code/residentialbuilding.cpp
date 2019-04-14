#include "residentialbuilding.h"

ResidentialBuilding::ResidentialBuilding(std::string address, std::string mission, size_t apartm_count,
                                         double area)
                   : Facility(address, mission, area), m_apartm_count(apartm_count)
{
}

std::string ResidentialBuilding::obj_data() const
{
    std::string base_info(Facility::obj_data());

    char buffer[57];

    sprintf(buffer, "Number of apartments: %d\n", m_apartm_count);

    base_info += (std::string)buffer;

    return base_info;
}

std::string ResidentialBuilding::class_name() const
{
    return "Class: ResidentialBuilding\n";
}

ResidentialBuilding::~ResidentialBuilding()
{
}
