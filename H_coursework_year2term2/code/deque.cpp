#include "deque.h"

Deque::Deque():head(nullptr), tail(nullptr), m_size(0) {}

unsigned int Deque::size()
{
    return m_size;
}

void Deque::push_front(CommercialOrg *data)
{
    Node *temp = new Node(data);//создаем узел temp который бедет хранить наши данные переданные в параметр фции
    temp->next = head;//следующий за узлом temp элемент - голова
    temp->prev = nullptr;//предыдущий перед узлом temp элемент - пустой

    if (head)//если голова существует, то
        head->prev = temp;//предыдущий перед головой элемент будет temp

    head = temp;//голова = temp

    if (!tail)//если хвост не существует, то в деке только один элемент который мы как раз добавили
        tail = head;//хвост равен голове (а в голове на данный момент храниться temp)

    m_size++;//увеличиваем длину списка на 1 т к добавили  1 элемент
}

CommercialOrg *Deque::pop_front()
{
    CommercialOrg *data(nullptr);//создаем дату и заполняем ее нулем

    if (head)//если голова есть, значит можем ее отрезать
    {
        data = head->data;//копируем в переменную данных(data) данные из головы

        Node *temp = head;//создаем временный узел temp и присваиваем в него голову
        head = head->next;//перемещаем голову на 1 позицию

        if (head)//если новая голова (мы ее перместили) существует, то
            head->prev = nullptr;//"говорим" ей о том что перед ней элемент (то есть старая голова) будет удален

        delete temp;//удаляем temp то есть старую голову
        m_size--;//уменьшаем сайз
    }

    return data;//возвращаем данные которые хранились в голове которую мы отрезали
}

CommercialOrg *Deque::pop_back()
{
    CommercialOrg *data(nullptr);//создаем переменную для данных из хвоста

    if (tail)//если есть хвост значит его можно отрезать
    {
        data = tail->data;//переносим в переменную данных(data) данные из хвоста

        Node *temp = tail;//создаем временный узел temp куда присваиваем хвост
        tail = tail->prev;//передвигаем хвост на шаг назад

        if (tail)//если новый хвост существует
            tail->next = nullptr;//показываем что за ним не будет элементов

        delete temp;//удаляем старый хвост
        m_size--;//уменьшаем сайз

    }

    return data;//возвращаем данные
}

void Deque::clear()
{
    Node *temp;//создаем временный узел temp
    while (head)//пока голова существует
    {
        temp = head;//присваиваем в temp head
        head = head->next;//перемещаем голову
        delete temp;//удаляем temp - старую голову
    }
    head = nullptr; tail = nullptr;//явно указываем что дек пуст
    m_size = 0;
}

Deque::~Deque()
{
    {
        clear();//вызываем фкцию очистки
    }
}


Deque::Node::Node(CommercialOrg *data):next(nullptr), prev(nullptr)
{
    {

        if (Bank *ptr = dynamic_cast<Bank *>(data))
        {
            this->data = new Bank;
            *(this->data) = *data;
        }
        else
        {
            this->data = new InsuranceComp;
            *(this->data) = *data;
        }
    }
}

Deque::Node &Deque::Node::operator=(const Deque::Node &node)
{
    next = node.next;
    prev = node.prev;
    if (Bank *ptr = dynamic_cast<Bank *>(data))
    {
        delete data;//----
        data = new Bank;
        *data = *node.data;
    }
    else
    {
        delete data;//-----
        data = new InsuranceComp;
        *data = *node.data;
    }

    return *this;
}
