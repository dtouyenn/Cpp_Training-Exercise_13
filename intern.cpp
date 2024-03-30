#include "intern.hpp"

Intern::Intern(std::string major, std::string semester, std::string university_name)
    : _major {major}, _semester {semester}, _university_name {university_name}
{

}

Intern::Intern(std::string id, std::string fullname, std::string birthday, std::string phone,
    std::string email, int employee_type, std::list<Certificate> cer,
    std::string major, std::string semester, std::string university_name)
    : Employee(id, fullname, birthday, phone, email, employee_type, cer),
    _major {major}, _semester {semester}, _university_name {university_name}
{

}

void Intern::ShowInfor()
{
    Employee::ShowInfor();
    std::cout << std::setw(10) << " ";
    std::cout << std::setw(20) << "|Major";
    std::cout << std::setw(20) << "|Semester";
    std::cout << std::setw(20) << "|University";
    std::cout << std::endl;
    std::cout << std::setw(10) << "";
    std::cout << std::setw(20) << _major;
    std::cout << std::setw(20) << _semester;
    std::cout << std::setw(20) << _university_name;
    std::cout << std::endl;
}