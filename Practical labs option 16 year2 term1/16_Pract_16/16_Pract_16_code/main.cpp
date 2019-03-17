#include <iostream>
#include <ctime>
#include <algorithm>

#define SIZE_QUEUE 20

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *head;
    Node *tail;
};

Queue *make_queue()
{
    Queue *q = new Queue();
    q->head = nullptr;
    q->tail = nullptr;
    return q;
}

int pop(Queue *q)
{
    //if (q->head == nullptr)
    //{
     //   throw std::logic_error("Head equals NULL. Queue appears to be empty");
    //}
    int head_element_data = q->head->data;
    Node *temp = q->head;

    q->head = q->head->next;
    delete temp;


    return head_element_data;
}

void push(Queue *q, int data)
{
    Node *new_element = new Node();
    new_element->data = data;
    new_element->next = nullptr;


    if (q->head == nullptr && q->tail == nullptr)
    {
        q->head = new_element;
        q->tail = new_element;
    }
    else
    {
        q->tail->next = new_element;
        q->tail = q->tail->next;
    }
}

int get_max_element(Queue *q)
{
    int max_data = 0;

    Node *end_qeue = q->tail;

    while (q->head != end_qeue)
    {
        if (q->head->data > max_data)///
        {   max_data = q->head->data;}

        int temp_data = pop(q);
        push(q, temp_data);
    }

    if (q->head->data > max_data)///
    {   max_data = end_qeue->data;}

    int temp_data = pop(q);
    push(q, temp_data);

    std::cout << "Max element: " << max_data << std::endl;

    return max_data;
}

void main_chore(Queue *q, int max_element)
{
    Node *end_of_queue = q->tail;

    push(q, max_element);

    while (q->head != end_of_queue)
    {
        if (q->head->data == max_element)
        {
            pop(q);
        }
        else
        {
            int temp = pop(q);
            push(q, temp);
        }
    }

    if (q->head->data == max_element)
    {
        pop(q);
    }
    else
    {
        int temp = pop(q);
        push(q, temp);
    }
}

void clear(Queue *q)
{
    Node *temp;

    while (q->head != nullptr)
    {
        pop(q);

    }

    delete q;
    q = nullptr;
}

void show(Queue *q)
{
    std::cout << "---------------------------\n";

    Node *temp;
    temp = q->head;

    while (temp != nullptr)
    {
        std::cout << temp->data << std::endl;

        temp = temp->next;
    }

    std::cout << "...........................\n";
}

int main()
{
    Queue *q = make_queue();

    int arr[SIZE_QUEUE];
    std::iota(arr, arr+SIZE_QUEUE, -10);
    std::random_shuffle(arr, arr+SIZE_QUEUE);
    for(int i = 0; i < SIZE_QUEUE; ++i)
    {
        push(q, arr[i]);
    }

    show(q);
    int max = get_max_element(q);
    main_chore(q, max);
    show(q);
    clear(q);

    return 0;
}
