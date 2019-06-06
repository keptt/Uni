#include "readfromfile.h"
#include <iostream>
#include "bank.h"
#include "insurancecompany.h"
#include "commercialorganisation.h"

ReadFromFile::ReadFromFile(Deque &collection):collection(&collection)
{}

bool ReadFromFile::read(string filename)
{
    fin.open(filename);
    if (!fin.is_open())
    {
       cout << "Error of reading data\n";
        return false;
    }

    string type;
    string data;
    CommercialOrg *temp(nullptr);

    while (!fin.eof())
    {
        getline(fin, type);//первое что записано в файле это тип объекта затем в идут все поля этого объекта каждый на новой строке
		
        if (type == "Bank")//определяем тип объекта и считываем данные из файла в объект подходящего типа (Bank или InsuranceComp)
            temp = new Bank;
        else if (type == "InsuranceComp")
            temp = new InsuranceComp;
		else
			temp = nullptr;

		if (temp)
		{
			getline(fin, data);
			temp->setBranchesQuantity(stoi(data));
			getline(fin, data);
			temp->setClientsQuantity(stoi(data));
			getline(fin, data);
			temp->setStatMoneyCapital(stoi(data));
			getline(fin, data);
			temp->setDescription(data);
			getline(fin, data);
			temp->setHqCountry(data);
			getline(fin, data);
			temp->setName(data);
			getline(fin, data);
			temp->setWorkersQuantity(stoi(data));

			if (type == "Bank")//определяем тип объекта и считываем данные из файла в объект подходящего типа (Bank или InsuranceComp)
			{
				getline(fin, data);
				((Bank *)(temp))->setCashYearlyFlow(stoi(data));
			}
			else
			{
				getline(fin, data);
				((InsuranceComp *)(temp))->setInsuranceConditions(data);
				getline(fin, data);
				((InsuranceComp *)(temp))->setInsuranceType(data);
				getline(fin, data);
				((InsuranceComp *)(temp))->setMinInsuranceSum(stoi(data));
			}

			collection->pushFront(temp);
		}
    }

    fin.close();

    return true;
}
