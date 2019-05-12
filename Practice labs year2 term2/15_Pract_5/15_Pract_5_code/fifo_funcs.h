#include <iostream>
#include "fifo.h"

using namespace std;

template<class T>
Fifo<T>::Fifo():head(nullptr), tail(nullptr), size(0)
{
}

template<class T>
Fifo<T>::Fifo(const Fifo<T>& second)
{
    copy(second);
}

template<class T>
Fifo<T>::~Fifo()
{
    clear();
}

template<class T>
Fifo<T> & Fifo<T>::operator=(const Fifo<T> & second)
{
    if (this == &second)
        return *this;

    copy(second);

    return *this;
}

template<class T>
void Fifo<T>::copy(const Fifo<T>& second)
{
    Node<T> *temp_second = second.head;

    if (temp_second)
    {
        head = new Node<T>;

        Node<T> *temp = head;

        while (temp_second)
        {
            temp->data = temp_second->data;
            temp->next = temp_second->next;

            if (temp_second->next)
            {
                temp->next = new Node<T>;
                temp = temp->next;
            }

            temp_second = temp_second->next;
        }

        tail = temp;
        tail->next = nullptr;
        size = second.size;
    }
    else
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
}

template<class T>
inline bool Fifo<T>::isEmpty()
{
        return size;
}

template<class T>
inline unsigned int Fifo<T>::getSize()
{
    return size;
}

template<class T>
inline void Fifo<T>::clear()
{
    Node<T> *temp = head;
    while (temp)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
    tail = nullptr;
    size = 0;
}

template<class T>
inline void Fifo<T>::show()
{
    if (!head)
    {
        cout << "queue is empty\n";
        return;
    }

    Node<T> *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

template<class T>
inline void Fifo<T>::pushBack(T data)
{
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = nullptr;

    if (!head)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
    size++;
}

template<class T>
inline void Fifo<T>::popFront()
{
    if (!head)
    {
        std::cout << "Queue is empty\n";
        return;;
    }

    Node<T> *temp = head;
    head = head->next;

    !head ? tail = nullptr : true;

    delete temp;
    size--;
}

template<class T>
inline T Fifo<T>::getFront()
{
    if (!head)
    {
        std::cout << "Queue is empty\n";
        return T();//
    }

    return head->data;
}




//template<class T>
//void Fifo<T>::copy(const Fifo<T>& second)
//{
//	Node<T> *temp_second = second.head;
//
//	if (temp_second)
//	{
//		head = new Node<T>;
//	}
//	else
//	{
//		head = nullptr;
//	}
//
//	Node<T> *temp = head;
//
//	while (temp_second)
//	{
//		temp->data = temp_second->data;
//		temp->next = temp_second->next;
//
//		if (temp_second->next)
//		{
//			temp->next = new Node<T>;
//			temp = temp->next;
//		}
//
//		temp_second = temp_second->next;
//	}
//
//	tail = temp;
//	if (temp)
//	{
//		temp->next = nullptr;
//	}
//	size = second.size;
//}
