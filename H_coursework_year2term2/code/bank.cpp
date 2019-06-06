#include "bank.h"
#include <iostream>

using namespace std;

Bank::Bank():CommercialOrg()
{
    cashYearlyFlow = 0;
}

Bank::Bank(string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
           unsigned int statMoneyCapital, /*const string *partnerships,*/ string &hqCountry, string &description, /*int *cardPaySystems,*/
           int cashYearlyFlow): 
           CommercialOrg (name, workersQuantity, clientsQuantity, branchesQuantity, statMoneyCapital, hqCountry, description),
           cashYearlyFlow(cashYearlyFlow)
{
}

Bank::~Bank()
{}

void Bank::setCashYearlyFlow(int cashYearlyFlow)
{
    this->cashYearlyFlow = cashYearlyFlow;
}

int Bank::getCashYearlyFlow() const
{
    return cashYearlyFlow;
}

void Bank::print() const
{
    CommercialOrg::print();

    cout << "Cash Yearly Flow: " << cashYearlyFlow << endl;
}




