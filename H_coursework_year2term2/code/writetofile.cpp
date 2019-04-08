#include "writetofile.h"
#include "commercialorganisation.h"
#include "insurancecompany.h"
#include "bank.h"

WriteToFile::WriteToFile(Deque &collection):collection(&collection)//ofstream gets initialized autmatically
{}

bool WriteToFile::write(std::string filename)
{
    fout.open(filename);//открываем файл

    if (!fout.is_open())//если открыть не удалось выводим ошибку и возвращаем ложь
    {
        std::cout << "Error writing to file\n";
        return false;
    }

    while (collection->size() != 0)//непосредственно запись в зависимости от типа к которому принадлежит объект
    {
        CommercialOrg *currentObj = collection->pop_front();//--
        if (Bank *temp = dynamic_cast<Bank *>(currentObj))
        {
            fout << "Bank\n";//первое что записываем это тип объекта, затем его поля
            fout << currentObj->getBranchesQuality();
            fout << currentObj->getClientsQuantity();
            fout << currentObj->getDescription();
            fout << currentObj->getHqCountry();
            fout << currentObj->getName();
            fout << currentObj->getWorkersQuantity();
            fout << ((Bank *)currentObj)->getCashYearlyFlow();
        }
        else
        {
            fout << "InsuranceComp";
            fout << currentObj->getBranchesQuality();
            fout << currentObj->getClientsQuantity();
            fout << currentObj->getDescription();
            fout << currentObj->getHqCountry();
            fout << currentObj->getName();
            fout << currentObj->getWorkersQuantity();
            fout << ((InsuranceComp *)currentObj)->getInsuranceConditions();
            fout << ((InsuranceComp *)currentObj)->getInsuranceType();
            fout << ((InsuranceComp *)currentObj)->getMinInsuranceSum();
        }
    }

    return true;
}

