#ifndef FIFO_H
#define FIFO_H
#include<queue>
#include<iostream>

template <class T>
class Fifo{
    std::queue<T> q;
public:
    Fifo() = default;
    Fifo(const Fifo<T> &second) = default;
    ~Fifo() = default;

    Fifo<T> &operator=(const Fifo<T> &second) = default;

    bool isEmpty();
    unsigned int getSize();

    void clear();
    template<typename Tt>
    friend std::ostream &operator<<(std::ostream &out, Fifo<Tt> &q);

    void pushBack(T data);
    void popFront();
    T getFront();
};

#endif // FIFO_H
