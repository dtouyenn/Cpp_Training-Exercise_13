#ifndef _EXPERIENCE_H_
#define _EXPERIENCE_H_

#include "employee.hpp"

class Experience : public Employee
{
private:
    unsigned int _expln_year;
    std::string _pro_skill;
public:
    virtual void ShowInfor() override;
    Experience() = default;
    Experience(unsigned int expln_year, std::string pro_skill);
    Experience(std::string id, std::string fullname, std::string birthday, std::string phone,
    std::string email,int employee_type, std::list<Certificate> cer,
    unsigned int expln_year, std::string pro_skill);


};




#endif