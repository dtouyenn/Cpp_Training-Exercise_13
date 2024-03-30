#ifndef _EXCEP_H_
#define _EXCEP_H_

#include <string>
#include <sstream>

class DateException:public std::runtime_error
{
public:
    DateException(): std::runtime_error {"Invalid Date"}
    {}
};

class EmailException:public std::runtime_error
{
public:
    EmailException(): std::runtime_error {"Invalid Email"}
    {}
};

class PhoneException:public std::runtime_error
{
public:
    PhoneException(): std::runtime_error {"Invalid Phone"}
    {}
};

class NameException:public std::runtime_error
{
public:
    NameException(): std::runtime_error {"Invalid Name"}
    {}
};


void isValidDateFormat(const std::string& date);
void isValidEmail(const std::string& email);
void isValidPhoneNumber(const std::string& phoneNumber);
void isValidName(const std::string& name);

#endif