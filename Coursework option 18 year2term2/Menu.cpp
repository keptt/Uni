#include "Menu.h"
#include <fstream>
#include <algorithm>

/*--------------------------------------------------------------------------------------------------------*/
void clean_before_getline_eats()
{
	std::cin.ignore(100, '\n');
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::input_base_obj_data(Assignment * obj)
{
	std::string strdata;
	size_t numdata;

	std::cout << "Input name: ";
	clean_before_getline_eats();
	std::getline(std::cin, strdata);
	obj->set_name(strdata);

	std::cout << "Input id: ";
	std::cin >> numdata;
	obj->set_id(numdata);

	std::cout << "Input status: ";
	std::cin >> numdata;
	obj->set_status((eStatus)numdata);
	////verify

	std::cout << "Input start date: ";
	clean_before_getline_eats();
	std::getline(std::cin, strdata);
	obj->set_start_date(strdata);

	std::cout << "Input deadline: ";
	//clean_before_getline_eats();
	std::getline(std::cin, strdata);
	obj->set_deadline(strdata);

	std::cout << "Input description: ";
	//clean_before_getline_eats();
	std::getline(std::cin, strdata);
	obj->set_description(strdata);

	std::cout << "Input priority: ";
	std::cin >> numdata;
	obj->set_priority((ePriority)numdata);
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::add_defect_obj()
{
	Defect *obj = new Defect;
	input_base_obj_data(obj);

	std::string data;
	std::cout << "Input location: ";
	clean_before_getline_eats();
	std::getline(std::cin, data);
	obj->set_location(data);

	pq.push_back(obj, obj->get_priority());
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::add_development_problem_obj()
{
	DevelopmentProblem *obj = new DevelopmentProblem;
	input_base_obj_data(obj);

	std::string data;
	std::cout << "Input requirement: ";
	clean_before_getline_eats();
	std::getline(std::cin, data);
	obj->set_requirement(data);

	pq.push_back(obj, obj->get_priority());
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::run_main_task()
{
	//...
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::sort_container()
{
	std::cout << "Chose what field would you would like to sort by: "
		"1 - by name"
		"2 - by id"
		"3 - by priority";
	std::cin >> choice;

	switch (choice)	   //how to sort
	{
	case eByName:
		//...my_shiny_buzzy_sort_algorithm
		break;
	case eByID:
		//...my_shiny_buzzy_sort_algorithm
		break;
	case eByPriority:
		//...my_shiny_buzzy_sort_algorithm
		break;
	}
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::read_from_file()
{
	std::string filepath;
	std::cout << "Input file path: ";
	std::cin >> filepath;

	std::ifstream fin(filepath);

	if (!fin.is_open())
		throw std::logic_error("File oppening failure: ifstream object failed to open the file." 
			"File may not exist by the given path");

	std::string type;

	Assignment *read_obj;
	while (!fin.eof())
	{
		fin >> type;
		if (type == "Defect")
		{
			read_obj = new Defect;
			read_obj->input_obj(fin);
		}
		else
		{
			read_obj = new DevelopmentProblem;
			read_obj->input_obj(fin);
		}

		pq.push_back(read_obj, read_obj->get_priority());
	}

	fin.close();
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::write_to_file()
{
	std::string filepath;
	std::cout << "Input file path: ";
	std::cin >> filepath;

	std::ofstream fout(filepath);

	if (!fout.is_open())
		throw std::logic_error("File oppening failure: ofstream object failed to open the file");

	pq.output_content(fout);

	fout.close();
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::clear_container()
{
	pq.clear();
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::show_elements()
{
	pq.output_content(std::cout);
}

/*--------------------------------------------------------------------------------------------------------*/
Menu &Menu::menu()
{
	static Menu m;
	return m;
}

/*--------------------------------------------------------------------------------------------------------*/
void Menu::run()
{
	do
	{
		std::cout << "\n---------MENU-----------\n"
			"<1>.Add Defect\n"
			"<2>.Add Development Problem\n"
			"<3>.Run main task\n"
			"<4>.Sort container\n"
			"<5>.Read from file\n"
			"<6>.Write to file\n"
			"<7>.Clear container\n"
			"<8>.Show elements\n"
			"<9>.Exit\n"
			"Input: ";

		std::cin >> choice;

		switch (choice)
		{
		case eAddDefect:
			add_defect_obj();
			std::cout << "Done\n";
			break;
		case eAddDevelopmentProblem:
			add_development_problem_obj();
			std::cout << "Done\n";
			break;
		case eRunMainTask:
			run_main_task();
			std::cout << "Done\n";
			break;
		case eSortContainer:
			sort_container();
			std::cout << "Done\n";
			break;
		case eReadFromFile:
			read_from_file();
			std::cout << "Done\n";
			break;
		case eWriteToFile:
			write_to_file();
			std::cout << "Done\n";
			break;
		case eClearContainer:
			clear_container();
			std::cout << "Done\n";
			break;
		case eShowElements:
			show_elements();
			std::cout << "Done\n";
			break;
		case eExit:
			break;
		default:
			std::cout << "Bad input\n";
			system("cls");
		}
	} 
	while (choice != eExit);
}
