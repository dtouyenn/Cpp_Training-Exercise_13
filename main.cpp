#include <iostream>
#include "UI.hpp"

int main()
{
    UI uiManager;
    int choice;
    while (1)
    {
        std::cout << "\n**************Manager Employee**************" << std::endl;
        std::cout << "Enter 1: To insert " << std::endl;
        std::cout << "Enter 2: To search " << std::endl;
        std::cout << "Enter 3: Show all a type of Employee" << std::endl;
        std::cout << "Enter 4: Show All" << std::endl;
        std::cout << "Enter 5: Delete by ID" << std::endl;
        std::cout << "Enter 6: Exit " << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
            uiManager.insertEmployee();
            break;
        case 2:
            uiManager.findID();
            break;
        case 3:
            uiManager.findAllType();
            break;
        case 4:
            uiManager.ShowAll();
            break;
        case 5:
            uiManager.deleteID();
            break;
        case 6:
            return 0;
            break;
        default:
            std::cout << "Invalid value. Please enter new choice: " << std::endl;
            break;
        }
    }
    
    return 0;
}