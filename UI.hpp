#ifndef _UI_HPP_
#define _UI_HPP_

#include "manager.hpp"
#include "excep.hpp"

class UI
{
private:
    Manager _manager_employees;
public:
    void deleteID();
    void findID();
    void insertEmployee();
    void findAllType();
    void ShowAll();
};


#endif