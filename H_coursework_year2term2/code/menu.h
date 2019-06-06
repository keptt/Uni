#ifndef MENU_H
#define MENU_H
#include "commercialorganisation.h"
#include "bank.h"
#include "insurancecompany.h"
class Deque; 

class Menu//синглтон-класс меню (позволяет создать один и только один объект класса)
{
private:
//--------------------------------------------------------------------------------------//
    int answer;//переменная которая используется внутри функции run и принимает инпут пользователя
//--------------------------------------------------------------------------------------//
    Menu();//конструктор находится в приватной части чтобы мы не могли его вызвать и создать н-ное к-во объектов
    void addBank(Deque &d);
    void addInsuranceComp(Deque &d);
    void writeToFile(Deque &d);
    void readFromFile(Deque &d);
    void mainTask(Deque &d);
    void handleFuncExceptions(void(Menu::*funcMemPoint)(Deque &), Deque &collection);
    void inBaseObj(CommercialOrg *org);
    void inBank(Bank *bank);
    void inInsuranceComp(InsuranceComp *icomp);
//--------------------------------------------------------------------------------------//
public:
//--------------------------------------------------------------------------------------//
    static Menu &createMenu();//статичиская функция в которой будет происходить создание объекта
//--------------------------------------------------------------------------------------//
    void run();//основная функция в которой реализовано само меню
//--------------------------------------------------------------------------------------//
};

#endif // MENU_H
