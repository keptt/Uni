#ifndef FIFOFUNCS_H
#define FIFOFUNCS_H
#include "Fifo.h"

template<class T>
bool Fifo<T>::isEmpty()
{
    return q.empty();
}

template<class T>
unsigned int Fifo<T>::getSize()
{
    return q.size();
}

template<class T>
void Fifo<T>::clear()
{
    if (q.empty())
    {
        std::cout << "Queue is empty!\n";
        return;
    }

    while (!q.empty())
    {
        q.pop();
    }
}

template<class T>
void Fifo<T>::pushBack(T data)
{
    q.push(data);
}

template<class T>
void Fifo<T>::popFront()
{
    if (q.empty())
    {
        std::cout << "Nothing to remove. Queue is empty!\n";
        return;
    }

    q.pop();
}

template<class T>
T Fifo<T>::getFront()
{
    if (q.q.empty())
    {
        std::cout << "Nothing to show. Queue is empty!";
    }

    return q.front();
}

template<class Tt>
std::ostream &operator<<(std::ostream &out, Fifo<Tt> &q)
{
    if (q.q.empty())
    {
        std::cout << "Nothing to show. Queue is empty!";
        return out;
    }

    std::queue<Tt> new_q(q.q);

    while (!q.q.empty())
    {
        out << q.q.front() << " ";
        q.q.pop();
    }

    q.q = new_q;

    return out;
}

#endif // FIFOFUNCS_H
