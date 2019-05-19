#pragma once
#include <iostream>
#include  <queue>
#include "node.hpp"

template <typename T>
class Queue
{
private:
	std::queue<T> q;

public:
    Queue() = default;;
    Queue(const Queue<T> &other) = default;;

    size_t size() const;
    bool is_empty() const;

    void push_back(T data);
    void erase_front();

    Queue<T> &operator=(const Queue<T> &other) = default;
    template<typename Tt>
    friend std::ostream &operator<<(std::ostream &out, Queue<Tt> queue);

    void clear();
    ~Queue() = default;;
};
