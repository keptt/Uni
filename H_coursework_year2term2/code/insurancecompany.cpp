#include "insurancecompany.h"
#include <iostream>

InsuranceComp::InsuranceComp():CommercialOrg()
{
    insuranceType = "";
    insuranceConditions = "";
    minInsuranceSum = 0;
}

InsuranceComp::InsuranceComp(std::__cxx11::string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
                             std::__cxx11::string &hqCountry, std::__cxx11::string &description, std::__cxx11::string &insuranceType,
                             std::__cxx11::string &insuranceConditions, int minInsuranceSum):CommercialOrg (name, workersQuantity, clientsQuantity, branchesQuantity,
                                                                                       hqCountry, description)
{
    this->insuranceType = insuranceType;
    this->insuranceConditions = insuranceConditions;
    this->minInsuranceSum = minInsuranceSum;
}

InsuranceComp::~InsuranceComp()
{}

void InsuranceComp::setInsuranceType(std::string &insuranceType)
{
    this->insuranceType = insuranceType;
}

void InsuranceComp::setInsuranceConditions(std::string &insuranceConditions)
{
    this->insuranceConditions = insuranceConditions;
}

void InsuranceComp::setMinInsuranceSum(int insuranceSum)
{
    this->minInsuranceSum = insuranceSum;
}

std::string InsuranceComp::getInsuranceType()
{
    return insuranceType;
}

std::string InsuranceComp::getInsuranceConditions()
{
    return insuranceType;
}

int InsuranceComp::getMinInsuranceSum()
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
