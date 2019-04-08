#ifndef DEQUE_H
#define DEQUE_H
#include "commercialorganisation.h"
#include "insurancecompany.h"
#include "bank.h"

#pragma once

class Deque//класс-контейнер дек с ограниченным входом
{
private:
    class Node//внутренний класс, который репрезентирует узлел дека
    {
    public:
        CommercialOrg *data;//данные узла
        Node *next;//указатель на следующий элемент
        Node *prev;//указатель на предыдущий элемент
        Node(CommercialOrg *data);//контсруктор узла, который присваивает в узел данные

        Node &operator=(const Node &node);//перегрузка оператора присвоения
    };
    //ниже поля самого дека, а не его узла
    Node *head;//указатель на узел "голову" дека
    Node *tail;//указатель на узел "хвост" дека
    unsigned int m_size;//количиство элементов дека, тип size_t это в некотором роде псевдоним к типу unsigned int

public:
    Deque();//конструктор дека по умолчанию

    unsigned int size();//функция возвращения длины

    void push_front(CommercialOrg *data);//функция для добавления элемента в начало дека

    CommercialOrg *pop_front();//функция удаления элемента с начала дека

    CommercialOrg *pop_back();//функция удаления элемента из конца дека (схема схожая с предыдущей функцией, но теперь режем хвост)

    void clear();//функция очистки дека

    ~Deque();//деструктор дека
};

#endif // DEQUE_H
