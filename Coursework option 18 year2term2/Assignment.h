#pragma once
#include <string>
#include <iostream>

enum eStatus : short
{
	inprogress = 0, done
};

enum ePriority :short
{
	low = 1, medium, high, urgent
};

class Assignment
{
protected:
	std::string m_name;
	size_t m_id;
	eStatus m_status;
	std::string m_start_date;
	std::string m_deadline;
	std::string m_description;
	ePriority m_priority;

public:
	Assignment();
	Assignment(std::string name, size_t id, short status, std::string start_date, std::string deadline, std::string description, short priority);
	std::string get_name() const;
	std::string get_deadline();
	size_t get_id() const;
	std::string get_start_date() const;
	eStatus get_status() const;
	ePriority get_priority() const;

	void set_name(std::string name);
	void set_description(std::string description);
	void set_start_date(std::string start_date);
	void set_deadline(std::string deadline);
	void set_id(size_t id);
	void set_status(eStatus status);
	void set_priority(ePriority priority);

	///virtual std::ostream &print_out(std::ostream &out) const = 0;
	///virtual std::ostream &enter_info(std::ostream &in) const = 0;

	virtual void output_obj(std::ostream &out) const = 0;
	virtual void input_obj(std::istream &in) = 0;

	///friend std::ofstream &operator<<(std::ofstream &fout, const Assignment *obj);
	///friend std::ifstream &operator>>(std::ifstream &fin, Assignment *obj);
	friend std::ostream &operator<<(std::ostream &out, const Assignment *obj);
	friend std::istream &operator>>(std::istream &in, Assignment *obj);

	virtual ~Assignment() = default;///
};

//std::ifstream in("FILENAME.smth");
//std::string s;
//char buffer[100];
//
//while (in)
//{
//	in.read(buffer, 100);
//	s.append(buffer, in.gcount());
//	
//}
