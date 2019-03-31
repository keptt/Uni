#include "apartments.h"
#include "appctainer.h"

int main()
{
    AppStruct a[] = {{(char *)"address", 3, 3, 120}, {(char *)"address2", 1, 1, 100}, {(char *)"address3", 3, 3, 333}, {(char *)"address4", 4, 4, 444}};

    AppCtainer ctainer(a, sizeof(a)/sizeof(a[0]));

    std::cout << "Apps between 4 and 9 floors: \n";
    ctainer.print_apps_between_floors(4, 9);
    std::cout << "\n\nApps with 3 rooms: \n";
    ctainer.print_apps_by_rooms(3);
    std::cout << "\n\nApps with area less than 350: \n";
    ctainer.print_apps_ofless_area(350);

    return 0;
}
