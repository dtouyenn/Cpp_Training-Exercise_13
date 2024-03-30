#include "Experience.h"

Experience::Experience(std::string ID, std::string fullName, std::string birthday, 
	std::string phone, std::string email, std::list<Certificate> cert, int type,
	float exYear, std::string Proskill)
	: Employee(ID, fullName, birthday, phone, email, cert, type)
{
	this->explnYear = exYear;
	this->Proskill = Proskill;
}

void Experience::setExYear(float years)
{
	this->explnYear = years;
}

void Experience::setProSkill(std::string skills)
{
	this->Proskill = skills;
}

float Experience::getExYear()
{
	return explnYear;
}

std::string Experience::getProSkill()
{
	return Proskill;
}

void Experience::showInfo()
{
	std::cout << "Employee ID: " + ID + "\n" +
		"Full name: " + fullName + "\n" +
		"Date of birth: " + birthDay + "\n" +
		"Phone: " + phone + "\n" +
		"Email: " + email + "\n" +
		"ExplnYear: " + std::to_string(explnYear) + "\n" +
		"ProSkill: " + Proskill + "\n" +
		"------Certificate------" + "\n" +
		showCert(cert);
}







