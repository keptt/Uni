#pragma once
#include "Assignment.h"

class Defect : public Assignment
{
private:
	std::string m_location;

public:
	Defect();
	Defect(std::string name, size_t id, short status, std::string start_date, std::string deadline, std::string description, short priority,
		std::string location);

	std::string get_location() const;

	void set_location(std::string location);

	void output_obj(std::ostream &out) const override;
	void input_obj(std::istream &in) override;

	~Defect() = default;
};

