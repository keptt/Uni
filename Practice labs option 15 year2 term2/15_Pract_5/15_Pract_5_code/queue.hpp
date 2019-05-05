#pragma once
#include <iostream>
#include "node.hpp"

template <typename T>
class Queue
{
private:
    Node<T> *m_head;
    Node<T> *m_tail;
    size_t m_size;

public:
    Queue();
    Queue(const Queue<T> &other);

    void swap(Queue<T> &other);

    size_t size() const;
    bool is_empty() const;

    void push_back(T data);
    void erase_front();

    Queue<T> &operator=(Queue<T> other);
    template<typename Tt>
    friend std::ostream &operator<<(std::ostream &out, const Queue<Tt> &queue);

    void clear();
    ~Queue();
};
