#include "experience.hpp"

Experience::Experience(unsigned int expln_year, std::string pro_skill)
    : _expln_year {expln_year}, _pro_skill {pro_skill}
{

}
Experience::Experience(std::string id, std::string fullname, std::string birthday, std::string phone,
    std::string email,int employee_type, std::list<Certificate> cer,
    unsigned int expln_year, std::string pro_skill)
    : Employee(id, fullname, birthday, phone, email, employee_type, cer), _expln_year {expln_year}, _pro_skill {pro_skill}
{

}

void Experience::ShowInfor()
{
    Employee::ShowInfor();
    std::cout << std::setw(10) << " ";
    std::cout << std::setw(20) << "|Experience Years";
    std::cout << std::setw(20) << "|Pro Skills";
    std::cout << std::endl;

    std::cout << std::setw(10) << "";
    std::cout << std::setw(20) << _expln_year;
    std::cout << std::setw(20) << _pro_skill;
    std::cout << std::endl;
}