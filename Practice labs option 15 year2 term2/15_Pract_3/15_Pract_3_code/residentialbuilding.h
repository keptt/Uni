#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H
#include "facility.h"

class ResidentialBuilding : public Facility
{
public:
    ResidentialBuilding(std::string address = "", std::string mission = "",
                        size_t apartm_count = 0, double_t area = 0);
    ~ResidentialBuilding();
    void print_out() const;
private:
    size_t m_apartm_count;
};

#endif // RESIDENTIALBUILDING_H
