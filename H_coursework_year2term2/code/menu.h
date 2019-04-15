#ifndef MENU_H
#define MENU_H
class Deque;

class Menu//синглтон-класс меню (позволяет создать один и только один объект класса)
{
private:
//--------------------------------------------------------------------------------------//
    int answer;//переменная которая используется внутри функции run и принимает инпут пользователя
//--------------------------------------------------------------------------------------//
    Menu();//конструктор находиться в приватной части чтобы мы не могли его вызвать и создать н-ное к-во объектов
//--------------------------------------------------------------------------------------//
public:
//--------------------------------------------------------------------------------------//
    static Menu &createMenu();//статичиская функция в которой будет происходить создание объекта
//--------------------------------------------------------------------------------------//
    void run();//основная функция в которой реализовано само меню
//--------------------------------------------------------------------------------------//
};

void addBank(Deque &d);
void addInsuranceComp(Deque &d);
void writeToFile(Deque &d);
void /*R*/readFromFile(Deque &d);

#endif // MENU_H
