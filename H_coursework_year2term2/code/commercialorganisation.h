#ifndef COMMERCIALORGANISATION_H
#define COMMERCIALORGANISATION_H
#include <string>
#include <utility>

//объявление основного класса иерархии
class CommercialOrg
{
protected://модификатор доступа, который позволяет блоку кода, который в нем находиться быть доступным в классах наследниках (переменные внизу доступны и в наследниках)
//--------------------------------------------------------------------------------------//
    unsigned int workersQuantity;//количество работников - целое, не отрицательное
    unsigned int clientsQuantity;//к-во клиентов - целое, не отрицательное
    unsigned int branchesQuantity;//к-во филиалов - целое, не отрицательное
    std::string name;//имя компании - строка
    //std::string *partnerships;//партнеры - массив строк
    std::string hqCountry;//страна головного офиса - строка
    std::string description;//описание - строка
//--------------------------------------------------------------------------------------//
public:
//--------------------------------------------------------------------------------------//
    CommercialOrg();//конструктор по умолчанию
    CommercialOrg(std::string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
                  /*const std::string *partnerships,*/ std::string &hqCountry, std::string &description);//конструктор с параметрами для создания объектов класса
    virtual ~CommercialOrg();//деструктор для удаления объектов класса
//--------------------------------------------------------------------------------------//
    //функции по установке значений переменным (сеттеры)
    void setClientsQuantity(unsigned int quantity);
    void setWorkersQuantity(unsigned int quantity);
    void setBranchesQuality(unsigned int branchesQuantity);
    void setName(std::string name);
    //void setPartnerships(const std::string *partnerships);
    void setHqCountry(std::string &hqCountry);
    void setDescription(std::string &description);

//--------------------------------------------------------------------------------------//
    //функции по чтению значений переменных (геттеры)
    std::string getName();
    unsigned int getClientsQuantity();
    unsigned int getWorkersQuantity();
    //std::pair<std::string*, size_t> getPartnerships();
    std::string getHqCountry();
    std::string getDescription();
    unsigned int getBranchesQuality();
//--------------------------------------------------------------------------------------//
    virtual void print() const = 0;
//--------------------------------------------------------------------------------------//
};

#endif // COMMERCIALORGANISATION_H
