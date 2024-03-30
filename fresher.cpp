#include "fresher.hpp"

Fresher::Fresher(std::string graduation_date, std::string graduation_rank, std::string education)
    : _graduation_date {graduation_date}, _graduation_rank {graduation_rank}, _education {education}
{

}

Fresher::Fresher(std::string id, std::string fullname, std::string birthday, std::string phone,
    std::string email,int employee_type, std::list<Certificate> cer,
    std::string graduation_date, std::string graduation_rank, std::string education)
    : Employee(id, fullname, birthday, phone, email, employee_type, cer),
    _graduation_date {graduation_date}, _graduation_rank {graduation_rank}, _education {education}
{

}

void Fresher::ShowInfor()
{
    Employee::ShowInfor();
    std::cout << std::setw(10) << " ";
    std::cout << std::setw(20) << "|Graduation date";
    std::cout << std::setw(20) << "|Graduation rank";
    std::cout << std::setw(20) << "|Education";
    std::cout << std::endl;
    std::cout << std::setw(10) << "";
    std::cout << std::setw(20) << _graduation_date;
    std::cout << std::setw(20) << _graduation_rank;
    std::cout << std::setw(20) << _education;
    std::cout << std::endl;
}