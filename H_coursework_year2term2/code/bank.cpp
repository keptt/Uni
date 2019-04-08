#include "bank.h"
#include <iostream>

Bank::Bank():CommercialOrg()
{
    cashYearlyFlow = 0;
}

Bank::Bank(std::__cxx11::string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
           /*const std::__cxx11::string *partnerships,*/ std::__cxx11::string &hqCountry, std::__cxx11::string &description,
           /*int *cardPaySystems,*/ int cashYearlyFlow):CommercialOrg (name, workersQuantity, clientsQuantity, branchesQuantity, hqCountry, description)
{
    this->cashYearlyFlow = cashYearlyFlow;
}

Bank::~Bank()
{}

void Bank::setCashYearlyFlow(int cashYearlyFlow)
{
    this->cashYearlyFlow = cashYearlyFlow;
}

int Bank::getCashYearlyFlow()
{
    return cashYearlyFlow;
}

void Bank::print() const
{
    CommercialOrg::print();

    std::cout << "Cash Yearly Flow: " << cashYearlyFlow << std::endl;
}




