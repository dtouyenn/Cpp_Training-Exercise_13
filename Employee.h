#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include<iostream>
#include<string>
#include<list>
#include"Certificate.h"
class Employee
{
protected:
	std::string ID;
	std::string fullName;
	std::string birthDay;
	std::string phone;
	std::string email;
	int typeEm;
	std::list<Certificate> cert;
public:
	//long employeeCount = 0;
	Employee(std::string ID, std::string fullName, std::string birthday,
	std::string phone, std::string email, std::list<Certificate> cert, int type);
	Employee();
	virtual ~Employee();
	void setID(std::string ID);
	void setBirth(std::string birth);
	void setFullName(std::string fullName);
	void setPhone(std::string phone);
	void setEmail(std::string email);
	void setCert(std::list<Certificate> cert);
	void setTypeEm(int type);
	std::string getID();
	std::string getBirthDay();
	std::string getFullName();
	std::string getPhone();
	std::string getEmail();
	std::list<Certificate> getCert();
	std::string showCert(std::list<Certificate> cert);
	int getTypeEm();
	virtual void showInfo();
};

#endif // !_EMPLOYEE_H_
