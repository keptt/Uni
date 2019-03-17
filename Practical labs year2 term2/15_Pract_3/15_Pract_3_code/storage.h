#ifndef STORAGE_H
#define STORAGE_H
#include "building.h"

class Storage : public Building{
private:
    std::string conditionsOfStoring;
public:
    Storage(const std::string&, double, const std::string&, const std::string&);//:Building(const std::string&, double, const std::string&);
    Storage();
    std::string getConditionsOfStoring() const;

    void print();
};

#endif // STORAGE_H
