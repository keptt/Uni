#pragma once
#include "facility.h"

class ResidentialBuilding : public Facility
{
public:
    ResidentialBuilding(std::string address = "", std::string mission = "",
                        size_t apartm_count = 0, double area = 0);
    std::string class_name() const override;
    std::string obj_data() const override;
    ~ResidentialBuilding() override;
private:
    size_t m_apartm_count;
};

