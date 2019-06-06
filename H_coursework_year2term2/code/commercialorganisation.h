#ifndef COMMERCIALORGANISATION_H
#define COMMERCIALORGANISATION_H
#include <string>
#include <utility>
using namespace std;

//объявление основного класса иерархии
class CommercialOrg
{
protected://модификатор доступа, который позволяет блоку кода, который в нем находиться быть доступным в классах наследниках (переменные внизу доступны и в наследниках)
//--------------------------------------------------------------------------------------//
    unsigned int workersQuantity;//количество работников - целое, не отрицательное
    unsigned int clientsQuantity;//к-во клиентов - целое, не отрицательное
    unsigned int branchesQuantity;//к-во филиалов - целое, не отрицательное
    unsigned int statMoneyCapital;//статутный денежный капитал, в int из-за округления данной позиции в меньшую сторону к долару (так как центы не релевантны)
    string name;//имя компании - строка
    //string *partnerships;//партнеры - массив строк
    string hqCountry;//страна головного офиса - строка
    string description;//описание - строка
//--------------------------------------------------------------------------------------//
public:
//--------------------------------------------------------------------------------------//
    CommercialOrg();//конструктор по умолчанию
    CommercialOrg(string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
                  unsigned int statMoneyCapital, /*const string *partnerships,*/ string &hqCountry, string &description);//конструктор с параметрами для создания объектов класса
    virtual ~CommercialOrg();//деструктор для удаления объектов класса
//--------------------------------------------------------------------------------------//
    //функции по установке значений переменным (сеттеры)
    void setClientsQuantity(unsigned int quantity);
    void setWorkersQuantity(unsigned int quantity);
    void setBranchesQuantity(unsigned int branchesQuantity);
    void setStatMoneyCapital(unsigned int capital);
    void setName(string name);
    //void setPartnerships(const string *partnerships);
    void setHqCountry(string &hqCountry);
    void setDescription(string &description);

//--------------------------------------------------------------------------------------//
    //функции по чтению значений переменных (геттеры)
    string getName() const;
    unsigned int getClientsQuantity() const;
    unsigned int getWorkersQuantity() const;
    unsigned int getStatMoneyCapital() const;
    //pair<string*, size_t> getPartnerships();
    string getHqCountry() const;
    string getDescription() const;
    unsigned int getBranchesQuantity() const;

    friend ostream &operator<<(ostream &output, const CommercialOrg *obj);
//--------------------------------------------------------------------------------------//
    virtual void print() const = 0;
//--------------------------------------------------------------------------------------//
};

#endif // COMMERCIALORGANISATION_H
