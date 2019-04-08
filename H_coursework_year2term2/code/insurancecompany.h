#ifndef INSURANCECOMPANY_H
#define INSURANCECOMPANY_H
#include "commercialorganisation.h"

class InsuranceComp : public CommercialOrg///TODO: add insurance type as enum
{
private://приватный спецификатор доступа; позволяет переменным ниже быть видимыми эксклюзивно в данном классе
//--------------------------------------------------------------------------------------//
    std::string insuranceType;//тип страховки - строка
    std::string insuranceConditions;//условия страховки - строка
    int minInsuranceSum;//минимальная сума страховки - строка
//--------------------------------------------------------------------------------------//
public:
//--------------------------------------------------------------------------------------//
    InsuranceComp();
    InsuranceComp(std::string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
                  /*const std::string *partnerships,*/ std::string &hqCountry, std::string &description, std::string &insuranceType,
                  std::string &insuranceConditions, int minInsuranceSum);//конструктор с параметрами
    ~InsuranceComp();//деструктор, всегда без параметров и только один
//--------------------------------------------------------------------------------------//
    //сеттеры
    void setInsuranceType(std::string &insuranceType);
    void setInsuranceConditions(std::string &insuranceConditions);
    void setMinInsuranceSum(int insuranceSum);
//--------------------------------------------------------------------------------------//
    //геттеры
    std::string getInsuranceType();
    std::string getInsuranceConditions();
    int getMinInsuranceSum();
//--------------------------------------------------------------------------------------//
    void print() const override;
};

#endif // INSURANCECOMPANY_H
