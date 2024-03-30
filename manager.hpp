#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "employee.hpp"
#include "experience.hpp"
#include "intern.hpp"
#include "fresher.hpp"

#include <memory>
#include <algorithm>

class Manager
{
private:
    std::list< std::unique_ptr<Employee> > l;
public:
    void insert(std::unique_ptr<Employee> &ptr);
    std::unique_ptr<Employee> findID(std::string ID);
    bool deleteID(std::string ID);
    Manager find_all_type(int type);
    void ShowAll();

};

#endif