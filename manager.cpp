#include "manager.hpp"


void Manager::insert(std::unique_ptr<Employee> &ptr)
{
    (*ptr).increase();
    l.push_back(std::move(ptr));
}

std::unique_ptr<Employee> Manager::findID(std::string ID)
{
    std::unique_ptr<Employee> ret = std::make_unique<Employee>();
    auto it = std::find_if(l.begin(), l.end(), [ID](const std::unique_ptr<Employee> &ptr)
        {return ID == ptr->getID();});
    if (it != l.end())
    {
        *ret = *(*it);
        return ret;
    }
    else
        return nullptr;   
}

bool Manager::deleteID(std::string ID)
{
    std::list< std::unique_ptr<Employee> >::iterator it = l.begin();
    while (it != l.end())
    {
        if( (*it)->getID() == ID)
        {
           l.erase(it);
           return true;
        }
        it++;
    }
    return false;   
}

Manager Manager::find_all_type(int type)
{
    Manager n_manager = {};
    std::unique_ptr<Employee> ptr = std::make_unique<Employee>();
    std::list< std::unique_ptr<Employee> >::iterator it = l.begin();
    if(type == EXPER)
    {
        while (it != l.end())
        {
            if( (*it)->GetType() == EXPER)
            {
                *ptr = *(*it);
                n_manager.insert(ptr);
            }
            it++;
        }
    }
    else if(type == FRESHER)
    {
        while (it != l.end())
        {
            if( (*it)->GetType() == FRESHER)
            {
                *ptr = *(*it);
                n_manager.insert(ptr);
            }
            it++;
        }
    }
    else if(type == INTERN)
    {
        while (it != l.end())
        {
            if( (*it)->GetType() == INTERN)
            {
                *ptr = *(*it);
                n_manager.insert(ptr);
            }
            it++;
        }
    }
    return n_manager;
}

void Manager::ShowAll()
{
    std::list< std::unique_ptr<Employee> >::iterator it = l.begin();
    int i = 1;
    while (it != l.end())
    {
        std::cout << "\nEMPLOYEE "<< i << std::endl;
        (*it)->ShowInfor();
        it++;
        i++;
    }
}