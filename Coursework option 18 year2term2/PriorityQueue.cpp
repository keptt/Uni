#include "PriorityQueue.h"

/*--------------------------------------------------------------------------------------------------------*/
PriorityQueue::PriorityQueue() :head(nullptr), tail(nullptr), m_size(0)
{
}

/*--------------------------------------------------------------------------------------------------------*/
size_t PriorityQueue::get_size()
{
	return m_size;
}

/*--------------------------------------------------------------------------------------------------------*/
void PriorityQueue::push_back(Assignment * data, size_t priority)
{
	Node *temp = new Node;
	temp->data = data;
	temp->priority = priority;

	Node *current = head;
	Node *previous = nullptr;
	while (current && current->priority <= priority)
	{
		previous = current;
		current = current->next;
	}
	if (current == head)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		temp->next = current;
		previous->next = temp;
	}
	++m_size;
}

/*--------------------------------------------------------------------------------------------------------*/
Assignment *PriorityQueue::pop_front()
{
	Assignment *data(nullptr);

	if (head)
	{
		if (Defect *cast_ptr = dynamic_cast<Defect *>(head->data))
		{
			data = new Defect;
			*data = *(head->data);
		}
		else
		{
			data = new DevelopmentProblem;
			*data = *(head->data);
		}

		Node *temp = head;

		head = head->next;
		delete temp;
		--m_size;
	}

	return data;
}

/*--------------------------------------------------------------------------------------------------------*/
void PriorityQueue::output_content(std::ostream &out)
{
	Node *temp = head;
	while (temp)
	{
		if (Defect *cast_ptr = dynamic_cast<Defect *>(temp->data))//if (typeid(*) == typeid())
		{
			out << "\nDefect\n";
		}
		else
		{
			out << "\nDevelopmentProblem\n";
		}
		temp->data->output_obj(out);//
		temp = temp->next;
	}
}

/*--------------------------------------------------------------------------------------------------------*/
void PriorityQueue::clear()
{
	Node *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	temp = nullptr;
	m_size = 0;
}

/*--------------------------------------------------------------------------------------------------------*/
PriorityQueue::~PriorityQueue()
{
	clear();
}
