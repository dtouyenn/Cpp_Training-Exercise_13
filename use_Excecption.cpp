#include"use_Exception.h"

bool check_date(std::string dates) {
    int date[3];
    std::string temp;
    int flag = 0;
    int i = 0;
    while ((flag = dates.find("-")) != std::string::npos) {
        temp = dates.substr(0, flag);
        date[i] = std::stoi(temp);
        dates.erase(0, flag + 1);
        i++;
    }
    date[2] = std::stoi(dates);
    if (date[0] < 0 || date[0] > 32) {
        return false;
    }
    if (date[1] < 0 || date[1] > 12) {
        return false;
    }
    return true;
}

bool check_phone(std::string phone)
{
    if (phone.size() == 10) {
        return true;
    }
    return false;
}

bool check_email(std::string mail)
{
    int flag1 = 0;
    int flag2 = 0;
    flag1 = mail.find('@');
    flag2 = mail.find('.');
    if (flag1 != 0 && flag2 != 0 && flag1 < flag2
        && flag1 != (mail.size() - 1) && flag2 != (mail.size() - 1)) {
        return true;
    }
    return false;
}

bool check_name(std::string name)
{
    for (int i = 0; i < name.size(); i++) {
        if (isdigit(name[i])) {
            return false;
        }
    }
    return true;
}
