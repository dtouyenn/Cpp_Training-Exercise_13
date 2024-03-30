#include "Company.h"

void Company::insertEm()
{
	std::cout << "--------Insert mode--------\n";
	std::string ID;
	std::cout << "Enter ID: ";
	std::cin >> ID;
	if (employees.size() > 0) {
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i]->getID() == ID) {
				employees[i]->showInfo();
				std::cout << "ID Da ton tai\n";
				return;
			}
		}
	}
	std::string fullname;
	while (true) {
		try {
			std::cout << "Enter fullname: ";
			std::cin.ignore();
			std::getline(std::cin, fullname);
			if (!check_name(fullname))
				throw 1;
			break;
		}
		catch (int& ex) {
			std::cerr << "Sorry, Name is invalid\n";
		}
	}
	std::string birth;
	while (true) {
		try {
			std::cout << "Enter date of birth (dd-mm-yyyy): ";
			std::cin >> birth;
			if (!check_date(birth))
				throw 1;
			break;
		}
		catch (int& ex) {
			std::cerr << "Sorry, date is invalid\n";
		}
	}
	std::string phone;
	while (true) {
		try {
			std::cout << "Enter phone number: ";
			std::cin >> phone;
			if (!check_phone(phone))
				throw 1;
			break;
		}
		catch (int& ex) {
			std::cerr << "Sorry, phone is invalid\n";
		}
	}
	std::string email;
	while (true) {
		try {
			std::cout << "Enter email: ";
			std::cin >> email;
			if (!check_email(email))
				throw 1;
			break;
		}
		catch (int& ex) {
			std::cerr << "Sorry, email is invalid\n";
		}
	}
	std::list<Certificate> certs;
	std::cout << "Enter number cert: ";
	int num;
	std::cin >> num;
	if (num > 0) {
		for (int i = 0; i < num; i++) {
			std::string certID;
			std::string certName;
			std::string certRank;
			std::string certDate;
			std::cout << "Enter Certificate ID: ";
			std::cin >> certID;
			std::cout << "Enter Certificate name: ";
			std::cin >> certName;
			std::cout << "Enter Rank: ";
			std::cin >> certRank;
			std::cout << "Enter date (dd-mm-yyyy): ";
			std::cin >> certDate;
			Certificate cert(certID, certName, certRank, certDate);
			certs.push_back(cert);
		}
	}
	std::cout << "Choose mode for complete info employee\n"
		<< "Enter 0 for Intern\n"
		<< "Enter 1 for Fresher\n"
		<< "Enter 2 for Experience\n";
	int type;
	std::cin >> type;
	while (1) {
		if (type == 0) {
			std::cout << "__Insert Intern information__\n";
			std::cout << "Enter Major: ";
			std::string major;
			std::cin >> major;
			std::cout << "Enter Semester: ";
			int semester;
			std::cin >> semester;
			std::cout << "Enter Education: ";
			std::string edu;
			std::cin >> edu;
			//Intern *ptr = new Intern;
			std::shared_ptr<Intern> ptr = std::make_shared<Intern>();
			ptr->setID(ID);
			ptr->setFullName(fullname);
			ptr->setBirth(birth);
			ptr->setPhone(phone);
			ptr->setEmail(email);
			ptr->setTypeEm(type);
			ptr->setCert(certs);
			ptr->setMajor(major);
			ptr->setSemester(semester);
			ptr->setUniName(edu);
			employees.push_back(std::move(ptr));
			std::cout << "Insert Successful\n";
			break;
		}
		if (type == 1) {
			std::cout << "__Insert Fresher information__\n";
			std::string graDate;
			std::string graRank;
			std::string graEdu;
			std::cout << "Enter graduation date(yy-mm-yyyy): ";
			std::cin >> graDate;
			std::cout << "Enter graduation rank: ";
			std::cin >> graRank;
			std::cout << "Enter Education: ";
			std::cin >> graEdu;
			//Fresher* ptr = new Fresher;
			std::shared_ptr<Fresher> ptr = std::make_shared<Fresher>();
			ptr->setID(ID);
			ptr->setFullName(fullname);
			ptr->setBirth(birth);
			ptr->setPhone(phone);
			ptr->setEmail(email);
			ptr->setTypeEm(type);
			ptr->setCert(certs);
			ptr->setGraDate(graDate);
			ptr->setGraRank(graRank);
			ptr->setGraEdu(graEdu);
			employees.push_back(std::move(ptr));
			std::cout << "Insert Successful\n";
			break;
		}
		if (type == 2) {
			std::cout << "__Insert Experience information__\n";
			float explnYear;
			std::string Proskill;
			std::cout << "Enter explnYear: ";
			std::cin >> explnYear;
			std::cout << "Enter ProSkill: ";
			std::cin >> Proskill;
			//Experience* ptr = new Experience;
			std::shared_ptr<Experience> ptr = std::make_shared<Experience>();
			ptr->setID(ID);
			ptr->setFullName(fullname);
			ptr->setBirth(birth);
			ptr->setPhone(phone);
			ptr->setEmail(email);
			ptr->setCert(certs);
			ptr->setTypeEm(type);
			ptr->setExYear(explnYear);
			ptr->setProSkill(Proskill);
			employees.push_back(std::move(ptr));
			std::cout << "Insert Successful\n";
			break;
		}
	}
}
bool Company::ereaseEm()
{
	std::cout << "\n--------Erease mode--------\n";
	std::string emID;
	std::cout << "Enter employee ID: ";
	std::cin >> emID;
	if (employees.empty()) {
		std::cout << "List employee!\n";
		return false;
	}
	auto it = employees.begin();
	for (it; it != employees.end(); it++) {
		if ((*it)->getID() == emID) {
			(*it)->showInfo();
			std::cout << "Do you want to erease this employee?\n";
			std::cout << "Enter 1 for Erease, 2 for Cancel: ";
			int temp;
			std::cin >> temp;
			if (temp == 1) {
				employees.erase(it);
				std::cout << "Erease successful\n";
				return true;
			}
			if (temp == 2) {
				std::cout << "Cancel this action!\n";
				return false;
			}
		}
	}
	std::cout << "Don't find this information!\n";
	return false;
}

void Company::findEm()
{
	std::cout << "\n--------Find infomation mode--------\n";
	std::string emID;
	std::cout << "Enter employee ID: ";
	std::cin >> emID;
	if (employees.empty()) {
		std::cout << "List employee is empty!\n";
	}
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getID() == emID) {
			employees[i]->showInfo();
		}
	}
	std::cout << "Don't find this information!\n";
}

void Company::editInf(std::string emID)
{
	std::cout << "\n--------Edit information mode--------\n";
	while (true)
	{
		std::cout << "Enter 1 for edit ID\n";
		std::cout << "Enter 2 for edit full name\n";
		std::cout << "Enter 3 for edit date of birth\n";
		std::cout << "Enter 4 for edit phone number\n";
		break;
	}
}

void Company::showList()
{
	std::cout << "\n--------Show information mode--------\n";
	if (employees.empty()) {
		std::cout << "List employee is empty!\n";
		return;
	}
	int tmp;
	std::cout << "Enter 1 for show all\n"
		<< "Enter 2 for show Intern\n"
		<< "Enter 3 for show Fresher\n"
		<< "Enter 4 for show Experiance\n";
	std::cin >> tmp;
	if (tmp == 1) {
		std::cout << "====List employees====\n";
		for (int i = 0; i < employees.size(); i++) {
			employees[i]->showInfo();
		}
	}
	if (tmp == 2) {
		std::cout << "====List Intern employees====\n";
		for (int i = 0; i < employees.size(); i++) {
			if(employees[i]->getTypeEm() == 0)
				employees[i]->showInfo();
		}
	}
	if (tmp == 3) {
		std::cout << "====List Fresher employees====\n";
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i]->getTypeEm() == 1)
				employees[i]->showInfo();
		}
	}
	if (tmp == 4) {
		std::cout << "====List Experiance employees====\n";
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i]->getTypeEm() == 2)
				employees[i]->showInfo();
		}
	}
}

std::shared_ptr<Employee> Company::find(std::string emID)
{
	std::shared_ptr<Employee> ptr;
	auto it = employees.begin();
	for (it; it != employees.end(); it++) {
		if ((*it)->getID() == emID) {
			ptr = *(it);
			return ptr;
		}
	}
	return nullptr;
}