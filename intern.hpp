#ifndef _INTERN_H_
#define _INTERN_H_

#include "employee.hpp"

class Intern : public Employee
{
private:
    std::string _major;
    std::string _semester;
    std::string _university_name;
public:
    virtual void ShowInfor() override;
    Intern() = default;
    Intern(std::string major, std::string semester, std::string university_name);
    Intern(std::string id, std::string fullname, std::string birthday, std::string phone,
    std::string email, int employee_type, std::list<Certificate> cer,
    std::string major, std::string semester, std::string university_name);
};

#endif