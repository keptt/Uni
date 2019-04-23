#pragma once
#include <iostream>
#include "Assignment.h"

class DevelopmentProblem : public Assignment
{
private:
	std::string m_requirement;

public:
	DevelopmentProblem();
	DevelopmentProblem(std::string name, size_t id, short status, std::string start_date, std::string deadline,
		std::string description, short priority, std::string requirements);

	std::string get_requirement() const;

	void set_requirement(std::string requirements);

	void output_obj(std::ostream &out) const override;
	void input_obj(std::istream &in) override;

	~DevelopmentProblem() = default;
};
