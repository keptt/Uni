#include "commercialorganisation.h"
#include <iostream>

using namespace std;

CommercialOrg::CommercialOrg():workersQuantity(0), clientsQuantity(0), branchesQuantity(0), name(""),
    hqCountry(""), description("")
{}

CommercialOrg::CommercialOrg(string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
                                           unsigned int statMoneyCapital, string &hqCountry, string &description):
    name(name), workersQuantity(workersQuantity), clientsQuantity(clientsQuantity), branchesQuantity(branchesQuantity),
    statMoneyCapital(statMoneyCapital), hqCountry(hqCountry)/*is valid?*/,
    description(description)
{}

CommercialOrg::~CommercialOrg()
{}

void CommercialOrg::setClientsQuantity(unsigned int quantity)
{
    clientsQuantity = quantity;
}

void CommercialOrg::setWorkersQuantity(unsigned int quantity)
{
    workersQuantity = quantity;
}

void CommercialOrg::setBranchesQuantity(unsigned int branchesQuantity)
{
    this->branchesQuantity = branchesQuantity;
}

void CommercialOrg::setStatMoneyCapital(unsigned int capital)
{
    statMoneyCapital = capital;
}

void CommercialOrg::setName(string name)
{
    this->name = name;
}

void CommercialOrg::setHqCountry(string &hqCountry)
{
    this->hqCountry = hqCountry;
}

void CommercialOrg::setDescription(string &description)
{
    this->description = description;
}

string CommercialOrg::getName() const
{
    return name;
}

unsigned int CommercialOrg::getClientsQuantity() const
{
    return clientsQuantity;
}

unsigned int CommercialOrg::getWorkersQuantity() const
{
    return workersQuantity;
}

unsigned int CommercialOrg::getStatMoneyCapital() const
{
    return statMoneyCapital;
}

string CommercialOrg::getHqCountry() const
{
    return hqCountry;
}

string CommercialOrg::getDescription() const
{
    return description;
}

unsigned int CommercialOrg::getBranchesQuantity() const
{
    return branchesQuantity;
}

ostream &operator<<(ostream &output, const CommercialOrg *obj)
{
    output << "====\n";
    obj->print();
    output << "====\n";
    return  output;
}

void CommercialOrg::print() const
{
    using namespace std;

    cout << "Name: " << name << endl;
    cout << "ClientsQuantity: " << clientsQuantity << endl;
    cout << "WorkersQuantity: " << workersQuantity << endl;
    cout << "Money Capital: " << statMoneyCapital << endl;
    cout << "HqCountry: " << hqCountry << endl;
    cout << "BranchesQuantuty: " << branchesQuantity << endl;
    cout << "Description: " << description << endl;
}
