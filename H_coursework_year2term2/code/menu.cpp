#include "menu.h"
#include "deque.h"
#include "writetofile.h"
#include "readfromfile.h"
#include <iostream>

using namespace std;

void Menu::handleFuncExceptions(void(Menu::*func_mem_ptr)(Deque &), Deque &collection)
{
    bool exception_occured;
    do
    {
        exception_occured = false;
        try
        {
            (this->*func_mem_ptr)(collection);
        }catch(logic_error e)
        {
            cin.clear();
            cout << e.what() << "\nTry again" << endl;
            exception_occured = true;
        }
    }while(exception_occured);
}

void Menu::inBaseObj(CommercialOrg *org)
{
    string data;
    try {
        cout << "input Name (string): ";
        getline(cin, data);
        org->setName(data);
        cout << "input BranchesQuality (integer): ";
        getline(cin, data);
        org->setBranchesQuantity(stoi(data));
        cout << "input ClientsQuantity (integer): ";
        getline(cin, data);
        org->setClientsQuantity(stoi(data));
        cout << "input StatMoneyCapital (integer): ";
        getline(cin, data);
        org->setStatMoneyCapital(stoi(data));
        cout << "input Description (string): ";
        getline(cin, data);
        org->setDescription(data);
        cout << "input HqCountry (string): ";
        getline(cin, data);
        org->setHqCountry(data);
        cout << "input WorkersQuantity (integer): ";
        getline(cin, data);
        org->setWorkersQuantity(stoi(data));
    } catch (invalid_argument r) {
        throw;
    }
}

void Menu::inBank(Bank *bank)
{
    string data;

    try {
        inBaseObj(bank);
        cout << "input CashYearlyFlow (integer): ";
        getline(cin, data);
    } catch (invalid_argument e) {
        throw;
    }
    bank->setCashYearlyFlow(stoi(data));
}

void Menu::inInsuranceComp(InsuranceComp *icomp)
{
    string data;

    try {
        inBaseObj(icomp);
        cout << "input InsuranceType (string): ";
        getline(cin, data);
        icomp->setInsuranceType(data);
        cout << "input InsuranceConditions (string): ";
        getline(cin, data);
        icomp->setInsuranceConditions(data);
        cout << "input MinInsuranceSum (integer): ";
        getline(cin, data);
        icomp->setMinInsuranceSum(stoi(data));
    } catch (invalid_argument e) {
        throw;
    }
}


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
    Deque collection;

    do
    {
        system("cls");//очищаем консоль от данных
        cout << "---------------------MENU-------------------\n";
        cout << "<1>.Add Bank object\n";
        cout << "<2>.Add Insurance Company object\n";
        cout << "<3>.Pop back element\n";
        cout << "<4>.Pop front element\n";
        cout << "<5>.Clear the deque\n";
        cout << "<6>.Move to the file\n";
        cout << "<7>.Load from the file\n";
        cout << "<8>.Show container\n";
        cout << "<9>.Sort objects\n";
        cout << "<10>.Do task\n";
        cout << "<11>.Exit\nInput: ";

        cin >> answer;
        cin.get();

        switch(answer)
        {
        case 1:
            handleFuncExceptions(&Menu::addBank, collection);
            cout << "Command Success\n";
            system("pause");
            break;
        case 2:
            handleFuncExceptions(&Menu::addInsuranceComp, collection);
            cout << "Command Success\n";
            system("pause");
            break;
        case 3:
            CommercialOrg* tmp = collection.popBack();
            cout << tmp ? "Command Success\n" : "Collection is empty\nCommand Success\n";
            delete tmp;
            system("pause");
            break;
        case 4:
            CommercialOrg* tmp = collection.popFront();
            cout << tmp ? "Command Success\n" : "Collection is empty\nCommand Success\n";
            delete tmp;
            system("pause");
            break;
        case 5:
            collection.clear();
            cout << "Collection emptied\nCommand Success\n";
            system("pause");
            break;
        case 6:
            handleFuncExceptions(&Menu::writeToFile, collection);
            cout << "Command Success\n";
            system("pause");
            break;
        case 7:
            handleFuncExceptions(&Menu::readFromFile, collection);
            cout << "Command Success\n";
            system("pause");
            break;
        case 8:
            cout << collection;
            cout << "Command Success\n";
            system("pause");
            break;
        case 9:
            collection.sortByCapital();
            cout << "Command Success\n";
            system("pause");
            break;
        case 10:
            handleFuncExceptions(&Menu::mainTask, collection);
            cout << "Command Success\n";
            system("pause");
            break;
        case 11:
            break;
        default:
            cout << "Incorrect input\n";
            system("pause");
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    while(answer != 11);
}

void Menu::addBank(Deque &d)
{
    CommercialOrg *bank = new Bank;
    //input bank;
    try {
        inBank((Bank *)bank);
    } catch (invalid_argument e)
    {
        throw logic_error(e.what() + (std::string)" issue. You entered wrong set of data");
    }
    d.pushFront(bank);

}

void Menu::addInsuranceComp(Deque &d)
{
    CommercialOrg *insComp = new InsuranceComp;
    //input insurance comp;
    try {
        inInsuranceComp((InsuranceComp *)insComp);
    } catch (invalid_argument e)
    {
        throw logic_error(e.what());
    }

    d.pushFront(insComp);

}

void Menu::writeToFile(Deque &d)
{
    WriteToFile wf(d);
    string filepath;
    cout << "Input filepath: ";
    cin >> filepath;

    try {
        wf.write(filepath);
    } catch (logic_error e) {
        throw;
    }
    if (!cin)
        throw logic_error("Wrong input\n");
}

void Menu::readFromFile(Deque &d)
{
    ReadFromFile rf(d);
    string filepath;
    cout << "Input filepath: ";
    cin >> filepath;

    try {
        rf.read(filepath);
    } catch (logic_error e) {
        throw;
    }
    if (!cin)
        throw logic_error("Wrong input\n");
}

void  Menu::mainTask(Deque &d)
{
    unsigned int capital;
    Deque d_cpy;

    cout << "Will find all organisations with Capital lower than given\n";

    if (!d.size())
    {
        cout << "Container is empty\n";
        return;
    }

    cout << "Input Money Capital as a positive integer: ";
    cin >> capital;

    if (!cin)
        throw logic_error("Wrong input\n");

    bool found = false;
	cout << "Organizations whose Money Capital is lower than the given one: ";
    while(d.size())
    {
        CommercialOrg *temp;
        temp = d.popFront();
		d_cpy.pushFront(temp);
        
        if (temp->getStatMoneyCapital() < capital)
        {
            cout << temp->getName() << "\n";
            found = true;
        }

    }
	if (!found)
		cout << " None\n";

	d = d_cpy;
}
