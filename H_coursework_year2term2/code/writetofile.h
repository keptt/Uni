#ifndef WRITETOFILE_H
#define WRITETOFILE_H
#include <fstream>
#include "deque.h"
#include <iostream>

class WriteToFile//класс для записи данных из программы в файл
{
private:
//--------------------------------------------------------------------------------------//
    Deque *collection;//поле содержащее дек, но при этом контроль над деком мы не получаем (указатель все еще ссылается на дек за пределами класса)
    std::ofstream fout;//объект стандартной библиотеки отвечающий за запись данных в файл
//--------------------------------------------------------------------------------------//
public:
//--------------------------------------------------------------------------------------//
    WriteToFile(Deque &collection);//конструктор принимающий дек
//--------------------------------------------------------------------------------------//
    bool write(std::string filename);//функция записи в файл, возвращает ложь если запись не удалась, принимает имя файла
//--------------------------------------------------------------------------------------//
};

#endif // WRITETOFILE_H
