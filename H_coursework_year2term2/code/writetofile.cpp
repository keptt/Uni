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
        CommercialOrg *currentObj = collection->popFront();//--
        Bank *temp(nullptr);

        if (temp = dynamic_cast<Bank *>(currentObj))
            fout << "Bank\n";//первое что записываем это тип объекта, затем его поля
        else
            fout << "InsuranceComp\n";

        fout << currentObj->getBranchesQuantity() << "\n";
        fout << currentObj->getClientsQuantity() << "\n";
        fout << currentObj->getStatMoneyCapital() << "\n";
        fout << currentObj->getDescription() << "\n";
        fout << currentObj->getHqCountry() << "\n";
        fout << currentObj->getName() << "\n";
        fout << currentObj->getWorkersQuantity() << "\n";

        if (temp)
        {
            fout << ((Bank *)currentObj)->getCashYearlyFlow() << "\n";
        }
        else
        {
            fout << ((InsuranceComp *)currentObj)->getInsuranceConditions() << "\n";
            fout << ((InsuranceComp *)currentObj)->getInsuranceType() << "\n";
            fout << ((InsuranceComp *)currentObj)->getMinInsuranceSum() << "\n";
        }
    }

    fout.close();

    return true;
}

