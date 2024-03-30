#include "Employee.h"

Employee::Employee(std::string ID, std::string fullName, std::string birthday, std::string phone, std::string email, std::list<Certificate> cert, int type)
{
	this->ID = ID;
	this->fullName = fullName;
	this->birthDay = birthday;
	this->phone = phone;
	this->email = email;
	this->cert = cert;
	this->typeEm = type;
}

Employee::Employee()
{
}

Employee::~Employee()
{
}

void Employee::setID(std::string ID)
{
	this->ID = ID;
}

void Employee::setBirth(std::string birth)
{
	this->birthDay = birth;
}

void Employee::setFullName(std::string fullName)
{
	this->fullName = fullName;
}

void Employee::setPhone(std::string phone)
{
	this->phone = phone;
}

void Employee::setEmail(std::string email)
{
	this->email = email;
}

void Employee::setCert(std::list<Certificate> cert)
{
	this->cert = cert;
}

void Employee::setTypeEm(int type)
{
	this->typeEm = type;
}

std::string Employee::getID()
{
	return ID;
}

std::string Employee::getBirthDay()
{
	return birthDay;
}

std::string Employee::getFullName()
{
	return fullName;
}

std::string Employee::getPhone()
{
	return phone;
}

std::string Employee::getEmail()
{
	return email;
}

std::list<Certificate> Employee::getCert()
{
	return cert;
}

std::string Employee::showCert(std::list<Certificate> cert)
{
	std::string show = "";
	std::list<Certificate>::iterator it;
	for (it = cert.begin(); it != cert.end(); it++) {
		show += it->showCert();
	}
	return show;
}

int Employee::getTypeEm()
{
	return typeEm;
}

void Employee::showInfo()
{
}