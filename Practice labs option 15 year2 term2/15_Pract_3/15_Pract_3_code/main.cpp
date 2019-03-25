#include <iostream>
#include "facility.h"
#include "warehouse.h"
#include "residentialbuilding.h"

int main()
{
    ResidentialBuilding rb("351234513", "wqereqwrt", 1124, (double_t)234.345);
    Warehouse wh("56783", "edsfgkjfdsj", "good", (double_t)345.4);

    Facility *facility_ptr;

    facility_ptr = &rb;

    facility_ptr->print_out();

    facility_ptr = &wh;

    facility_ptr->print_out();

    return 0;
}
