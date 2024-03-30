#ifndef _INTERN_H_
#define _INTERN_H_
#include"Employee.h"
class Intern : public Employee
{
private:
	std::string major;
	int semester;
	std::string uniName;
public:
	Intern() = default;
	Intern(std::string ID, std::string fullName, std::string birthday,
		std::string phone, std::string email, std::list<Certificate> cert, int type,
		std::string major, int semester, std::string uniName);
	void setMajor(std::string major);
	void setSemester(int semester);
	void setUniName(std::string uniName);
	std::string getMajor();
	int getSemester();
	std::string getUniName();
	void showInfo();
};
#endif // !_INTERN_H_


