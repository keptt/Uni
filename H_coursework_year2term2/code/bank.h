#ifndef BANK_H
#define BANK_H
#include "commercialorganisation.h"

using namespace std;

class Bank : public CommercialOrg//наследование от базового класса иерархии в результате чего данный класс будет содержать в себе все поля (переменные) и
                                 //методы (функции) базового класса
{
private:
//--------------------------------------------------------------------------------------//
//    enum{
//        visa = 0, masterCard, payPal   //перечисление - условно, псевдоним для целого типа данных в данном случае на промежутке от 0 до 3
//        //каждая цифра отвечает соответствующей системе оплаты
//    };
//--------------------------------------------------------------------------------------//
    //int *cardPaySystems;//система оплаты через карту - массив целых чисел, которые будут в диапазоне указанном выше в перечислении. Таким образом каждое из
    //из этих чисел будет соответствовать оприделенной системе оплаты
    int cashYearlyFlow;//годовой оборот денег
public:
//--------------------------------------------------------------------------------------//
    Bank();
    Bank(string &name, unsigned int workersQuantity, unsigned int clientsQuantity, unsigned int branchesQuantity,
         unsigned int statMoneyCapital, /*const string *partnerships,*/ string &hqCountry, string &description, /*int *cardPaySystems,*/
         int cashYearlyFlow);//конструктор с параметрами
    ~Bank();//деструктор
//--------------------------------------------------------------------------------------//
    //сетеры
    void setCashYearlyFlow(int cashYearlyFlow);
    //void setCardPaySystems(int *cardPatSystems);
//--------------------------------------------------------------------------------------//
    //геттеры
    int getCashYearlyFlow() const;
    //pair<int *, size_t> getCardPaySystems();
//--------------------------------------------------------------------------------------//
    void print() const;
//--------------------------------------------------------------------------------------//
};

#endif // BANK_H
