#include "Defect.h"

/*--------------------------------------------------------------------------------------------------------*/
Defect::Defect()
{
}

/*--------------------------------------------------------------------------------------------------------*/
Defect::Defect(std::string name, size_t id, short status, std::string start_date, std::string deadline,
	std::string description, short priority, std::string location):Assignment(name, id, status, start_date, deadline,
		description, (ePriority)priority), m_location(location)
{
}

/*--------------------------------------------------------------------------------------------------------*/
std::string Defect::get_location() const
{
	return m_location;
}

/*--------------------------------------------------------------------------------------------------------*/
void Defect::set_location(std::string location)
{
	m_location = location;
}

/*--------------------------------------------------------------------------------------------------------*/
void Defect::output_obj(std::ostream &out) const
{
	Assignment::output_obj(out);
	out << "location of occurrence: " << m_location << "\n";
}

/*--------------------------------------------------------------------------------------------------------*/
void Defect::input_obj(std::istream &in)
{
	Assignment::input_obj(in);
	in >> m_location;
}
