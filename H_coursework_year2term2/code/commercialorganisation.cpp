#include "commercialorganisation.h"
#include <iostream>


CommercialOrg::CommercialOrg():workersQuantity(0), clientsQuantity(0), branchesQuantity(0), name(""),
    hqCountry(""), description("")
{}

CommercialOrg::CommercialOrg(std::__cxx11::string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
                             /*const std::__cxx11::string *partnerships,*/ std::__cxx11::string &hqCountry, std::__cxx11::string &description):
    name(name), workersQuantity(workersQuantity), clientsQuantity(clientsQuantity), branchesQuantity(branchesQuantity), hqCountry(hqCountry)/*is valid?*/,
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

void CommercialOrg::setBranchesQuality(unsigned int branchesQuantity)
{
    this->branchesQuantity = branchesQuantity;
}

void CommercialOrg::setName(std::string name)
{
    this->name = name;
}

void CommercialOrg::setHqCountry(std::string &hqCountry)
{
    this->hqCountry = hqCountry;
}

void CommercialOrg::setDescription(std::string &description)
{
    this->description = description;
}

std::string CommercialOrg::getName()
{
    return name;
}

unsigned int CommercialOrg::getClientsQuantity()
{
    return clientsQuantity;
}

unsigned int CommercialOrg::getWorkersQuantity()
{
    return workersQuantity;
}

std::string CommercialOrg::getHqCountry()
{
    return hqCountry;
}

std::string CommercialOrg::getDescription()
{
    return description;
}

unsigned int CommercialOrg::getBranchesQuality()
{
    return branchesQuantity;
}

void CommercialOrg::print()
{
    using namespace std;

    cout << "Name: " << name << endl;
    cout << "ClientsQuantity: " << clientsQuantity << endl;
    cout << "WorkersQuantity: " << workersQuantity << endl;
    cout << "HqCountry: " << hqCountry << endl;
    cout << "BranchesQuantuty: " << branchesQuantity << endl;
    cout << "Description: " << description << endl;
}
