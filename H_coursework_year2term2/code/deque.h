#ifndef DEQUE_H
#define DEQUE_H
#include "commercialorganisation.h"
#include "insurancecompany.h"
#include "bank.h"

using namespace std;

stuct Node//внутренний класс, который репрезентирует узлел дека
{
public:
    CommercialOrg *data;//данные узла
    Node *next;//указатель на следующий элемент
    Node *prev;//указатель на предыдущий элемент
};

class Deque//класс-контейнер дек с ограниченным входом
{
private:
    Node *head;//указатель на узел "голову" дека
    Node *tail;//указатель на узел "хвост" дека
    unsigned int size_;//количиство элементов дека, тип size_t это в некотором роде псевдоним к типу unsigned int
public:
    Deque();//конструктор дека по умолчанию

    unsigned int size() const;//функция возвращения длины

    void pushFront(CommercialOrg *data);//функция для добавления элемента в начало дека

    CommercialOrg *popFront();//функция удаления элемента с начала дека

    void sortByCapital ();

    CommercialOrg *popBack();//функция удаления элемента из конца дека (схема схожая с предыдущей функцией, но теперь режем хвост)

    void clear();//функция очистки дека

    friend ostream &operator<<(ostream &output, const Deque &d);

    ~Deque();//деструктор дека
};

#endif // DEQUE_H
