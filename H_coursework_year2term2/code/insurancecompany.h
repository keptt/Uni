#ifndef INSURANCECOMPANY_H
#define INSURANCECOMPANY_H
#include "commercialorganisation.h"

using namespace std;

class InsuranceComp : public CommercialOrg///TODO: add insurance type as enum
{
private://приватный спецификатор доступа; позволяет переменным ниже быть видимыми эксклюзивно в данном классе
//--------------------------------------------------------------------------------------//
    string insuranceType;//тип страховки - строка
    string insuranceConditions;//условия страховки - строка
    int minInsuranceSum;//минимальная сума страховки - строка
//--------------------------------------------------------------------------------------//
public:
//--------------------------------------------------------------------------------------//
    InsuranceComp();
    InsuranceComp(string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
                  unsigned int statMoneyCapital,
                  /*const string *partnerships,*/ string &hqCountry, string &description, string &insuranceType,
                  string &insuranceConditions, int minInsuranceSum);//конструктор с параметрами
    ~InsuranceComp();//деструктор, всегда без параметров и только один
//--------------------------------------------------------------------------------------//
    //сеттеры
    void setInsuranceType(string &insuranceType);
    void setInsuranceConditions(string &insuranceConditions);
    void setMinInsuranceSum(int insuranceSum);
//--------------------------------------------------------------------------------------//
    //геттеры
    string getInsuranceType() const;
    string getInsuranceConditions() const;
    int getMinInsuranceSum() const;
//--------------------------------------------------------------------------------------//
    void print() const;
};

#endif // INSURANCECOMPANY_H
