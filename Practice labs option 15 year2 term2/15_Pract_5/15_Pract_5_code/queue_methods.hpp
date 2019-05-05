#include "queue.hpp"

template<typename T>
Queue<T>::Queue() : m_head(nullptr), m_tail(nullptr), m_size(0)
{
}

template<typename T>
Queue<T>::Queue(const Queue<T> &other)
{
    Node<T> *current_other_node = other.m_head;
    Node<T> *current_current_node = nullptr;
    m_head = nullptr;
    if (current_other_node)
    {
        current_current_node = new Node<T>;
        current_current_node->data = current_other_node->data;
        m_head = current_current_node;
    }
    while (current_other_node && current_other_node->next)
    {
        current_current_node->next = new Node<T>;
        current_current_node->next->data = current_other_node->next->data;

        current_current_node = current_current_node->next;
        current_other_node = current_other_node->next;
    }
    if (current_current_node)
    {
        current_current_node->next = nullptr;
    }

    m_size = other.m_size;
}

template<typename T>
size_t Queue<T>::size() const
{
    return m_size;
}

template<typename T>
bool Queue<T>::is_empty() const
{
    return (!m_size) ? true : false;
}


template<typename T>
void Queue<T>::push_back(T data)
{
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = nullptr;

    if (m_tail)
    {
        m_tail->next = temp;
        m_tail = temp;
    }
    else
    {
       m_head =temp;
       m_tail = temp;
    }

    ++m_size;
}

template<typename T>
void Queue<T>::erase_front()
{
    Node<T> *temp = m_head;

    if (temp)
    {
        m_head = m_head->next;
        delete temp;
        --m_size;
    }
    else
    {
        std::cout << "dkw but noting to remove\n";
    }
}

template<typename T>
void Queue<T>::swap(Queue<T> &other)
{
    m_size = other.m_size;
    m_head = other.m_head;
    m_tail = other.m_tail;
}

template<typename T>
Queue<T> &Queue<T>::operator=(Queue<T> other)
{
    this->swap(other);

    return *this;
}

template<typename T>
void Queue<T>::clear()
{
    Node<T> *temp;

    while (m_head)
    {
        erase_front();
//        temp = m_head;
//        m_head = m_head->next;
//        delete temp;
    }

    m_size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    clear();
}

template<typename Tt>
std::ostream &operator<<(std::ostream &out, const Queue<Tt> &queue)
{
    if (!queue.m_head)
    {
        out << "queue is empty";
        return out;
    }

    Node<Tt> *temp = queue.m_head;

    while (temp)
    {
        out << temp->data << ' ';
        temp = temp->next;
    }

    return out;
}
