#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <iostream>
#include <string>
#include <list>
#include <iomanip>

typedef enum{
    EXPER = 0,
    FRESHER = 1,
    INTERN = 2
} TypeEmployee;
class Certificate;
class Employee
{
protected:
    std::string _id;
    std::string _fullname;
    std::string _birthday;
    std::string _phone;
    std::string _email;
    int _employee_type;
    static unsigned int _employee_count;
    std::list<Certificate> _cer;
public:
    Employee() = default;
    Employee(std::string id, std::string fullname, std::string birthday, std::string phone,
    std::string email, int _employee_type, std::list<Certificate> cer);
    virtual ~Employee();
    virtual void ShowInfor();
    std::string getID();
    void increase();
    int GetType();

};

class Certificate
{
friend class Employee;
friend std::ostream& operator<<(std::ostream &os, const Certificate &obj);
private:
    std::string _CerID;
    std::string _CerName;
    std::string _CerRank;
    std::string _CerDate;
public:
    Certificate(std::string CerID, std::string CerName, std::string CerRank, std::string CerDate);
    Certificate() = default;
};

#endif