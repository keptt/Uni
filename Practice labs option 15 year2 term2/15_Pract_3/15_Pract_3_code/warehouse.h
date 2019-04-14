#pragma once
#include "facility.h"

class Warehouse : public Facility
{
public:
    Warehouse(std::string address = "", std::string mission = "",
              std::string circs = "", double area = 0);
    std::string class_name() const override;
    std::string obj_data() const override;
    ~Warehouse() override;
private:
    std::string m_circs;
};

