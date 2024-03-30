#include "excep.hpp"

void isValidDateFormat(const std::string& date) {
    std::istringstream iss(date);
    std::string token;

    int day, month, year;

    for (char c : date) {
        if (!std::isdigit(c)) {
          if( c != '/' )  
            throw DateException();
        }
    }
    std::getline(iss, token, '/');
    if (!iss || token.empty()) {
         throw DateException();
    }
    day = std::stoi(token);
    if (day < 1 || day > 31) {
         throw DateException();
    }

    std::getline(iss, token, '/');
    if (!iss || token.empty()) {
         throw DateException();
    }
    month = std::stoi(token);
    if (month < 1 || month > 12) {
         throw DateException();
    }

    std::getline(iss, token);
    if (!iss || token.empty()) {
         throw DateException();
    }
    year = std::stoi(token);
    if (year < 0 || year > 2022 || year < 1900) {
         throw DateException();
    }

    bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    } else if (month == 2) {
        maxDay = leapYear ? 29 : 28;
    }
    if (day > maxDay) {
         throw DateException();
    }

}

void isValidEmail(const std::string& email) {
    std::istringstream iss(email);
    std::string token;

    std::getline(iss, token, '@');
    if (token.empty()) {
         throw EmailException();
    }

    std::getline(iss, token, '.');
    if (token.empty()) {
         throw EmailException();
    }

    std::getline(iss, token);
    if (token != "com" && token != "net" && token != "org" && token != "edu" && token != "vn") {
         throw EmailException();
    }
}

void isValidPhoneNumber(const std::string& phoneNumber) 
{
    if (phoneNumber.length() != 10) {
        throw PhoneException();
    }

    if (phoneNumber[0] != '0') {
        throw PhoneException();
    }

    for (size_t i = 1; i < phoneNumber.length(); ++i) {
        if (!std::isdigit(phoneNumber[i])) {
            throw PhoneException();
        }
    }
}

void isValidName(const std::string& name) 
{
    if (name.length() == 0 || name.length() >= 50) {
        throw NameException();
    }

    for (char c : name) {
        if (!std::isalpha(c)) {
            if( c != ' ')
                throw NameException();
        }
    }
}
