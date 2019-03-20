#include "building.h"

Building:: Building(const std::string& addressC, double sC, const std::string& purposeC):
    address(addressC), s(sC), purpose(purposeC){
}

Building::Building():address(""), s(0), purpose(""){
}

std::string Building::getAddress() const{
    return address;
}

double Building::getS() const{
    return s;
}

std::string Building::getPurpose() const{
    return purpose;
}

void Building::print()
{
    using namespace std;
    cout << "Adresa: " << address << endl;
    cout << "S: " << s << endl;
    cout << "Priznachennia: " << purpose << endl;
}

