#include "readfromfile.h"
#include <iostream>
#include "bank.h"
#include "insurancecompany.h"
#include "commercialorganisation.h"

ReadFromFile::ReadFromFile(Deque &collection):collection(&collection)
{}

bool ReadFromFile::read(std::string filename)
{
    fin.open(filename);
    if (!fin.is_open())
    {
       std::cout << "Error of reading data\n";
        return false;
    }
    std::string type;
    std::string data;
    std::getline(fin, type);//первое что записано в файле это тип объекта затем в идут все поля этого объекта каждый на новой строке

    while (!fin.eof())
    {
        CommercialOrg *temp(nullptr);
        if (type == "Bank\n")//определяем тип объекта и считываем данные из файла в объект подходящего типа (Bank или InsuranceComp)
        {
            Bank *temp = new Bank;
            std::getline(fin, data);
            temp->setBranchesQuality(std::stoi(data));
            std::getline(fin, data);
            temp->setClientsQuantity(std::stoi(data));
            std::getline(fin, data);
            temp->setDescription(data);
            std::getline(fin, data);
            temp->setHqCountry(data);
            std::getline(fin, data);
            temp->setName(data);
            std::getline(fin, data);
            temp->setWorkersQuantity(std::stoi(data));
            std::getline(fin, data);
            temp->setCashYearlyFlow(std::stoi(data));
        }
        else
        {
            InsuranceComp *temp = new InsuranceComp;
            std::getline(fin, data);
            temp->setBranchesQuality(std::stoi(data));
            std::getline(fin, data);
            temp->setClientsQuantity(std::stoi(data));
            std::getline(fin, data);
            temp->setDescription(data);
            std::getline(fin, data);
            temp->setHqCountry(data);
            std::getline(fin, data);
            temp->setName(data);
            std::getline(fin, data);
            temp->setWorkersQuantity(std::stoi(data));
            std::getline(fin, data);
            temp->setInsuranceConditions(data);
            std::getline(fin, data);
            temp->setInsuranceType(data);
            std::getline(fin, data);
            temp->setMinInsuranceSum(std::stoi(data));
        }
        collection->push_front(temp);
        std::getline(fin, type);
    }
    return true;
}

