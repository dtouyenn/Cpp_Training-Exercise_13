#ifndef _FRESHER_H_
#define _FRESHER_H_

#include "employee.hpp"

class Fresher : public Employee
{
private:
    std::string _graduation_date;
    std::string _graduation_rank;
    std::string _education;
public:
    virtual void ShowInfor() override;
    Fresher() = default;
    Fresher(std::string graduation_date, std::string graduation_rank, std::string education);
    Fresher(std::string id, std::string fullname, std::string birthday, std::string phone,
    std::string email,int employee_type, std::list<Certificate> cer,
    std::string graduation_date, std::string graduation_rank, std::string education);
};





#endif