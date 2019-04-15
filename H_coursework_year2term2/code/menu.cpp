#include "menu.h"
#include "deque.h"
#include "writetofile.h"
#include "readfromfile.h"
#include <iostream>

using namespace std;

Menu::Menu():answer(0)
{}

Menu &Menu::createMenu()
{
    static Menu menu;//создается статическая пременная меню, которая инициализируется только один раз, то есть при повторном вызове ф-ции новые инициализации
    //не произойдут и у нас так и останется лишь один объект класса
    return menu;//возвращаем единственный объект класса
}

void Menu::run()
{
    char input[3];
    do
    {
        system("clc");//очищаем консоль от данных
        cout << "---------------------MENU-------------------\n";
        cout << "<1>.Add Bank object\n";
        cout << "<2>.Add Insurance Company object\n";
        cout << "<3>.Pop back element\n";
        cout << "<4>.Pop front element\n";
        cout << "<5>.Clear the deque\n";
        cout << "<6>.Save to the file\n";
        cout << "<7>.Load from the file\n";
        cout << "<8>.Sort objects\n";
        cout << "<9>.Do task\n";
        cout << "<10>.Exit\n";

        cin.getline(input, 3);
        answer = atoi(input);

        Deque collection;

        switch(answer)
        {
        case 1:
            addBank(collection);
            cout << "Success\n";
            break;
        case 2:
            addInsuranceComp(collection);
            cout << "Success\n";
            break;
        case 3:
            collection.clear();
            cout << "Success\n";
            break;
        case 4:
            collection.pop_back();
            cout << "Success\n";
            break;
        case 5:
            collection.pop_back();
            cout << "Success\n";
            break;
        case 6:
            writeToFile(collection);
            cout << "Success\n";
            break;
        case 7:
            readFromFile(collection);
            cout << "Success\n";
            break;
        case 8:
            //sort
            break;
        case 9:
            //do task
            break;
        case 10:
            break;
        //....
        default:
            cout << "Incorrect input\n";
        }
        cout << "Enter any key to continue: \n";
        getchar();
    }
    while(answer != 10);
}

void addBank(Deque &d)
{
    CommercialOrg *bank = new Bank;
    //input bank;
    d.push_front(bank);
    delete bank;
}

void addInsuranceComp(Deque &d)
{
    CommercialOrg *insComp = new InsuranceComp;
    //input bank;
    d.push_front(insComp);
    delete insComp;
}

void writeToFile(Deque &d)
{
    WriteToFile wf(d);
    string filepath;
    cout << "Input filepath: ";
    cin >> filepath;
    wf.write(filepath);
}

void /*R*/readFromFile(Deque &d)
{
    ReadFromFile rf(d);
    string filepath;
    cout << "Input filepath: ";
    cin >> filepath;
    rf.read(filepath);
}
