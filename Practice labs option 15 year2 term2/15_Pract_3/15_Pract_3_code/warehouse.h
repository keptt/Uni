#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "facility.h"

class Warehouse : public Facility
{
public:
    Warehouse(std::string address = "", std::string mission = "",
              std::string circs = "", double_t area = 0);
    void print_out() const;
    ~Warehouse();
private:
    std::string m_circs;
};

#endif // WAREHOUSE_H
