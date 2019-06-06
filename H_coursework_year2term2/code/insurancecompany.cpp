#include "insurancecompany.h"
#include <iostream>

using namespace std;

InsuranceComp::InsuranceComp():CommercialOrg()
{
    insuranceType = "";
    insuranceConditions = "";
    minInsuranceSum = 0;
}

InsuranceComp::InsuranceComp(string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
                                 unsigned int statMoneyCapital,
                                 /*const string *partnerships,*/ string &hqCountry, string &description, string &insuranceType,
                                 string &insuranceConditions, int minInsuranceSum)
                                 :CommercialOrg (name, workersQuantity, clientsQuantity, branchesQuantity, statMoneyCapital, hqCountry, description),
                                 insuranceType(insuranceType),
                                 insuranceConditions(insuranceConditions),
                                 minInsuranceSum(minInsuranceSum)
{
}

InsuranceComp::~InsuranceComp()
{}

void InsuranceComp::setInsuranceType(string &insuranceType)
{
    this->insuranceType = insuranceType;
}

void InsuranceComp::setInsuranceConditions(string &insuranceConditions)
{
    this->insuranceConditions = insuranceConditions;
}

void InsuranceComp::setMinInsuranceSum(int insuranceSum)
{
    this->minInsuranceSum = insuranceSum;
}

string InsuranceComp::getInsuranceType() const
{
    return insuranceType;
}

string InsuranceComp::getInsuranceConditions() const
{
    return insuranceType;
}

int InsuranceComp::getMinInsuranceSum() const
{
    return minInsuranceSum;
}

void InsuranceComp::print() const
{
    using namespace std;

    CommercialOrg::print();
    cout << "Insurance Type: " << insuranceType << endl;
    cout << "Insurance Conditions: " << insuranceConditions << endl;
    cout << "Minimal Insurance Sum: " << minInsuranceSum << endl;
}
