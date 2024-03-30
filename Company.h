#ifndef _COMPANY_H_
#define _COMPANY_H_
#include "Intern.h"
#include "Fresher.h"
#include "Experience.h"
#include<vector>
#include<memory>
#include "use_Exception.h"
class Company
{
private:
	std::vector<std::shared_ptr<Employee>> employees;
public:
	void insertEm();
	bool ereaseEm();
	void findEm();
	void editInf(std::string emID);
	void showList();
	//shared_ptr<Employee> find(std::string emID);
};
#endif // !_COMPANY_H_
