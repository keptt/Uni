#include "queue.hpp"

template<typename T>
size_t Queue<T>::size() const
{
    return q.size();
}

template<typename T>
bool Queue<T>::is_empty() const
{
    return size();
}


template<typename T>
void Queue<T>::push_back(T data)
{
	q.push(data);
}

template<typename T>
void Queue<T>::erase_front()
{
    if (q.size())
    {
		q.pop();
    }
    else
    {
        std::cout << "noting to remove somehow\n";
    }
}

template<typename T>
void Queue<T>::clear()
{
    while (q.size())
    {
		q.pop();
    }
}

template<typename Tt>
std::ostream &operator<<(std::ostream &out, Queue<Tt> q)
{
    if (!q.size())
    {
        out << "queue is empty somehow";
        return out;
    }

    while (q.size())
    {
        out << q.q.front() << ' ';
		q.erase_front();
    }
	out << '\n';

    return out;
}
