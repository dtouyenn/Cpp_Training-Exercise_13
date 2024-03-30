#include "Intern.h"

Intern::Intern(std::string ID, std::string fullName, std::string birthday, std::string phone,
	std::string email, std::list<Certificate> cert, int type,
	std::string major, int semester, std::string uniName) : Employee(ID, fullName, birthday, phone, email, cert, type)
{
	this->major = major;
	this->semester = semester;
	this->uniName = uniName;
}

void Intern::setMajor(std::string major)
{
	this->major = major;
}

void Intern::setSemester(int semester)
{
	this->semester = semester;
}

void Intern::setUniName(std::string uniName)
{
	this->uniName = uniName;
}

std::string Intern::getMajor()
{
	return major;
}

int Intern::getSemester()
{
	return semester;
}

std::string Intern::getUniName()
{
	return uniName;
}

void Intern::showInfo()
{
	std::cout << "Employee ID: " + ID + "\n" +
		"Full name: " + fullName + "\n" +
		"Date of birth: " + birthDay +"\n" +
		"Phone: " + phone + "\n" +
		"Email: " + email + "\n" + 
		"Major: " + major + "\n" +
		"Semester: " + std::to_string(semester) + "\n" +
		"University: " + uniName + "\n"
		"------Certificate------" + "\n" +
		showCert(cert);
}