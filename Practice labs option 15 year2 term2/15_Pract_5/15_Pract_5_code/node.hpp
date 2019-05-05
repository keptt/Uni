#pragma once

template <typename T>
struct Node
{
    Node<T> *next;
    T data;
};
