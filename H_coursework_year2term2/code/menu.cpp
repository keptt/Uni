#include "menu.h"
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
        cout << "<1>.Create Bank object\n";
        cout << "<2>.Create Insurance Company object\n";
        cout << "<3>.Create the deque\n";
        cout << "<4>.Remove the deque\n";
        cout << "<5>.Save to the file\n";
        cout << "<6>.Load from the file\n";
        cout << "<7>.Sort objects\n";
        cout << "<8>.Do task\n";
        cout << "<9>.Exit\n";

        cin.getline(input, 3);
        answer = atoi(input);

        switch(answer)
        {
        //Q&Q:
        //все что сделать в мейне, так это вызвать меню и все?
        //дописывать ли меню новый функционал, не только пункты выше
        //как создавать банк и страховую компанию (пункт 1 и 2), если без контейнера в них не будет смысла?
        case 1:
            //как лучше реализовывать выполнение пунктов меню? через сторонние функции, которые в свою очередь взаимодействуют в классах? Разместить
            //их в отдельном файле?
            break;
        case 2:
            //....
            break;
        //....
        //считывание и запись в файл в отдельных классах? или в одном? или внутри контейнера?
        default:
            cout << "Incorrect input. Press enter to retry: ";
            getchar();
        }
    }
    while(answer != 9);
}
