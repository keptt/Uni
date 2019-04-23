#include "DevelopmentProblem.h"

/*--------------------------------------------------------------------------------------------------------*/
DevelopmentProblem::DevelopmentProblem()
{
}

/*--------------------------------------------------------------------------------------------------------*/
DevelopmentProblem::DevelopmentProblem(std::string name, size_t id, short status, std::string start_date,
	std::string deadline, std::string description, short priority, std::string requirements) : 
	Assignment(name, id, status, start_date, deadline, description, priority), 
	 m_requirement(requirements)
{
}

/*--------------------------------------------------------------------------------------------------------*/
std::string DevelopmentProblem::get_requirement() const
{
	return m_requirement;
}

/*--------------------------------------------------------------------------------------------------------*/
void DevelopmentProblem::set_requirement(std::string requirements)
{
	m_requirement = requirements;
}

/*--------------------------------------------------------------------------------------------------------*/
void DevelopmentProblem::input_obj(std::istream &in)
{
	Assignment::input_obj(in);
	in >> m_requirement;
}

/*--------------------------------------------------------------------------------------------------------*/
void DevelopmentProblem::output_obj(std::ostream &out) const
{
	Assignment::output_obj(out);
	out << "requirement: " << m_requirement << "\n";

}

