#ifndef BUILDING_H
#define BUILDING_H
#include <string>
#include <iostream>

class Building{
protected:
    std::string address;
    double s;
    std::string purpose;
public:
    Building(const std::string& address, double s, const std::string& purpose);
    Building();
    std::string getAddress() const;
    double getS() const;
    std::string getPurpose() const;
    virtual void print()=0;
};

#endif // BUILDING_H
