#pragma once
#include "Assignment.h"
#include "Defect.h"
#include "DevelopmentProblem.h"

struct Node
{
	Assignment *data;
	size_t priority;
	Node *next;
};

class PriorityQueue
{
private:
	Node *head;
	Node *tail;
	size_t m_size;

public:
	PriorityQueue();

	size_t get_size();

	void push_back(Assignment *data, size_t priority);

	Assignment *pop_front();
	
	void clear();

	void output_content(std::ostream &out);//everything else should ve in menu

	//writee to file in menu

	~PriorityQueue();
};

