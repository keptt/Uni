#include "Assignment.h"
#include <fstream>

/*--------------------------------------------------------------------------------------------------------*/
Assignment::Assignment()
{
}

/*--------------------------------------------------------------------------------------------------------*/
Assignment::Assignment(std::string name, size_t id, short status, std::string start_date, std::string deadline, 
	std::string description, short priority): m_name(name), m_id(id), m_status((eStatus)status),
	m_start_date(start_date), m_deadline(deadline), m_description(description), m_priority((ePriority)priority)
{
}

/*--------------------------------------------------------------------------------------------------------*/
std::string Assignment::get_name() const
{
	return m_name;
}

/*--------------------------------------------------------------------------------------------------------*/
std::string Assignment::get_deadline()
{
	return m_deadline;
}

/*--------------------------------------------------------------------------------------------------------*/
size_t Assignment::get_id() const
{
	return m_id;
}

/*--------------------------------------------------------------------------------------------------------*/
std::string Assignment::get_start_date() const
{
	return m_start_date;
}

/*--------------------------------------------------------------------------------------------------------*/
eStatus Assignment::get_status() const
{
	return (eStatus)m_status;
}

/*--------------------------------------------------------------------------------------------------------*/
ePriority Assignment::get_priority() const
{
	return m_priority;
}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::set_name(std::string name)
{
	m_name = name;
}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::set_description(std::string description)
{
	m_description = description;
}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::set_start_date(std::string start_date)
{
	m_start_date = start_date;
}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::set_deadline(std::string deadline)
{
	m_deadline = deadline;
}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::set_id(size_t id)
{
	m_id = id;
}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::set_status(eStatus status)
{
	m_status = status;
}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::set_priority(ePriority priority)
{
	m_priority = priority;
}

//Assignment::~Assignment()
//{
//}

//void Assignment::read_from_file(std::ifstream &fin) 
//{
//	fin >> m_name
//		>> m_status
//		>> m_start_date
//		>> m_deadline
//		>> m_description;
//}
//
//void Assignment::write_to_file(std::ofstream &fout) const
//{
//	fout << "Name: " << m_name << "\n"
//	<< "Status: " << m_status << "\n"
//	<< "Beginning date: " << m_start_date << "\n"
//	<< "Deadline date: " << m_deadline << "\n"
//	<< "Description: " << m_description << "\n";
//}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::output_obj(std::ostream &out) const
{
	out << "Name: " << m_name << "\n"
		 << "Status: " << m_status << "\n"
		 << "ID: " << m_id << "\n"
		 << "Beginning date: " << m_start_date << "\n"
		 << "Deadline date: " << m_deadline << "\n"
		 << "Description: " << m_description << "\n"
		 << "Priority: " << m_priority << "\n";
}

/*--------------------------------------------------------------------------------------------------------*/
void Assignment::input_obj(std::istream &in)
{
	in >> m_name
		>> *(short *)&m_status
		>> m_id
		>> m_start_date
		>> m_deadline
		>> m_description
		>> *(short *)&m_priority;
}

/*--------------------------------------------------------------------------------------------------------*/
std::ostream &operator<<(std::ostream &out, const Assignment *obj)
{
	obj->output_obj(out);

	return out;
}

/*--------------------------------------------------------------------------------------------------------*/
std::istream &operator>>(std::istream &in, Assignment *obj)
{
	obj->input_obj(in);

	return in;
}
