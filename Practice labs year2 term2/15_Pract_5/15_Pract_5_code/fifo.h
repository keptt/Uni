#pragma once

template<class T>
struct Node{
	Node<T> *next;
	T data;
};

template <class T>
class Fifo{
	unsigned int size;
	Node<T> *head;
	Node<T> *tail;
public:
	Fifo();
	Fifo(const Fifo<T> &second);
	~Fifo();
	void copy(const Fifo<T> &second);

	Fifo<T> &operator=(const Fifo<T> &second);

	bool isEmpty();
	unsigned int getSize();

	void clear();
	void show();

	void pushBack(T data);
	void popFront();
	T getFront();
};
