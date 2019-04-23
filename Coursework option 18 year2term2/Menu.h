#pragma once
#include "PriorityQueue.h"

enum eActions: short
{
	eAddDefect = 1, eAddDevelopmentProblem, 
	eRunMainTask, eSortContainer,
	eReadFromFile, eWriteToFile,
	eClearContainer, eShowElements,
	eExit
};

enum eSortby: short
{
	eByName = 1, eByID, eByPriority
};

class Menu
{
private:
	short choice;
	PriorityQueue pq;

	Menu() = default;
	void input_base_obj_data(Assignment *obj);
	void add_defect_obj();
	void add_development_problem_obj();
	void run_main_task();
	void sort_container();
	void read_from_file();
	void write_to_file();
	void clear_container();
	void show_elements();

public:
	static Menu &menu();
	void run();

	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;

	~Menu() = default;
};

