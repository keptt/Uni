#include <iostream>
#include <flat.h>
using namespace std;

void print(const flat &f)
{
    cout << "Adres - " << f.get_address() << endl;
    cout << "Plosh'ya - " << f.get_S() << endl;
    cout << "Poverh - " << f.get_floor() << endl;
    cout << "K-st' kimnat - " << f.get_num_rooms() << endl;
}

int main()
{
    flat *obj = new flat(const_cast<char *>("Frankfurt street"), 24, 456, 34);
    print(*obj);
    cout << endl << endl;
    obj->set_address("Fruit street");
    obj->set_S(455);
    obj->set_floor(23);
    obj->set_num_rooms(33);
    print(*obj);

    delete obj;

    return 0;
}
