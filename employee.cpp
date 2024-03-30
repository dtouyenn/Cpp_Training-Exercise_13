#include "employee.hpp"

unsigned int Employee::_employee_count = 0;

Employee::Employee(std::string id, std::string fullname, std::string birthday, std::string phone,
    std::string email, int employee_type, std::list<Certificate> cer)
    : _id {id}, _fullname {fullname}, _birthday {birthday}, _phone {phone}, _email {email}, _employee_type {employee_type}, _cer {cer}
{

}

Certificate::Certificate(std::string CerID, std::string CerName, std::string CerRank, std::string CerDate)
    : _CerID { CerID}, _CerName { CerName}, _CerRank {CerRank}, _CerDate {CerDate}
{}

std::ostream &operator<<(std::ostream &os, const Certificate &obj)
{
    os << std::left;
    os << std::setw(10) << " ";
    os << std::setw(10) << obj._CerID;
    os << std::setw(10) << obj._CerName;
    os << std::setw(10) << obj._CerRank;
    os << std::setw(10) << obj._CerDate;

    return os;
}

std::string Employee::getID()
{
    return _id;
}

int Employee::GetType()
{
    return _employee_type;
}

void Employee::increase()
{
    _employee_count++;
}

Employee::~Employee()
{
    _employee_count--;
}

void Employee::ShowInfor()
{
    std::cout << std::left;
    std::cout << std::setw(10) << "ID";
    std::cout << std::setw(30) << "|Full Name";
    std::cout << std::setw(12) << "|Birthday";
    std::cout << std::setw(12) << "|Phone";
    std::cout << std::setw(20) << "|Email";
    std::cout << std::setw(12) << "|Type";
    std::cout << std::setw(12) << "|NumCerti";
    std::cout << std::endl;
    std::cout << std::setw(10) << _id;
    std::cout << std::setw(30) << _fullname;
    std::cout << std::setw(12) << _birthday;
    std::cout << std::setw(12) << _phone;
    std::cout << std::setw(20) << _email;
    if( _employee_type == EXPER)
    {
        std::cout << std::setw(12) << "Experience";
    }
    else if(_employee_type == FRESHER)
    {
        std::cout << std::setw(12) << "Fresher";
    }
    else
    {
        std::cout << std::setw(12) << "Intern";
    }
    std::cout << std::setw(12) << _cer.size();
    std::cout << std::endl;

    std::cout << std::setw(10) << " ";
    std::cout << std::setw(10) << "|CerID";
    std::cout << std::setw(10) << "|CerName";
    std::cout << std::setw(10) << "|CerRank";
    std::cout << std::setw(10) << "|CerDate";
    std::cout << std::endl;
    std::list<Certificate>::iterator it = _cer.begin();
    while (it != _cer.end()) { 
        std::cout << *it << std::endl;
        it++;
    }

}
