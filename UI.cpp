#include "UI.hpp"

void UI::deleteID()
{
    std::string id;
    std::cout << "\n*** Delete by ID ***" << std::endl;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();
    if(_manager_employees.deleteID(id))
    {
        std::cout << "Delete complete" << std::endl;
    }
    else
    {
        std::cout << "Not found to delete" << std::endl;
    }    
}

void UI::findID()
{
    std::string id;
    std::unique_ptr<Employee> ptr; 

    std::cout << "\n*** Search ID ***" << std::endl;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();
    ptr = _manager_employees.findID(id);
    ptr->ShowInfor();    
}

void UI::insertEmployee()
{
    int employee_type;
    std::unique_ptr<Employee> ptr;
    /* All employee */
    std::string id;
    std::string fullname;
    std::string birthday;
    std::string phone;
    std::string email;
    std::list<Certificate> cer;
    int num_cer;
    std::string CerID;
    std::string CerName;
    std::string CerRank;
    std::string CerDate;
    /* Experience */
    unsigned int expln_year;
    std::string pro_skill;
    /* Fresher */
    std::string graduation_date;
    std::string graduation_rank;
    std::string education;
    /* Intern */
    std::string major;
    std::string semester;
    std::string university_name;

    Intern intern;
    Experience exper;
    Fresher fresh;
    std::string selection;
    std::cout << "\n*** Enter Informations of Employee ***" << std::endl;
    std::cout << "ID: ";
    std::getline(std::cin, id);
    if(_manager_employees.findID(id) != nullptr)
    {
        std::cout << "ID already exists. Do you want to modify (Y/N)?" << std::endl;
        std::cin >> selection;
        std::cin.ignore();
        std::transform(selection.begin(), selection.end(), selection.begin(), ::toupper);
        if( selection == "Y")
        {
            std::cout << "MODIFY" << std::endl;
            _manager_employees.deleteID(id);
        }
        else 
        {
            return;
        }
    }
    do
    {
        try
        {
            std::cout << "FullName: ";
            std::getline(std::cin, fullname);
            isValidName(fullname);
            break;
        }
        catch(const NameException& e)
        {
            std::cerr << e.what() << '\n';
        }
    } while(true);
    do
    {
        try
        {
            std::cout << "Birthday: ";
            std::getline(std::cin, birthday);
            isValidDateFormat(birthday);
            break;
        }
        catch(const DateException& e)
        {
            std::cerr << e.what() << '\n';
        }
    } while(true);

    do{
        try
        {
            std::cout << "Phone: ";
            std::getline(std::cin, phone);
            isValidPhoneNumber(phone);
            break;
        }
        catch(const PhoneException& e)
        {
            std::cerr << e.what() << '\n';
        }
    } while(true);
    do{
        try
        {
            std::cout << "Email: ";
            std::getline(std::cin, email);
            isValidEmail(email);
            break;
        }
        catch(const EmailException& e)
        {
            std::cerr << e.what() << '\n';
        }
    } while(true);          

    std::cout << "Number of certificated: ";
    std::cin >> num_cer;
    std::cin.ignore();
    for (int i = 1; i <= num_cer; i++)
    {
        std::cout << "Enter Cer: " << i << std::endl;
        std::cout << "     " << "CerID: ";
        std::getline(std::cin, CerID);
        std::cout << "     " << "CerName: ";
        std::getline(std::cin, CerName);
        std::cout << "     " << "CerRank: ";
        std::getline(std::cin, CerRank);
        do{
            std::cout << "     " << "CerDate: ";
            std::getline(std::cin, CerDate);
            try
            {
                isValidDateFormat(CerDate);
                break;
            }
            catch(const DateException& e)
            {
                std::cerr << e.what() << '\n';
            }
        } while(true);
        cer.push_back({CerID, CerName, CerRank, CerDate});
    }

    do
    {
        std::cout << "Employee type (0-Experience, 1-Fresher, 2-Intern): ";
        std::cin >> employee_type;
        std::cin.ignore();
        if(employee_type == EXPER)
        {
            std::cout << "Employee type: Experience" << std::endl;
            std::cout << "Expln Year: ";
            std::cin >> expln_year;
            std::cin.ignore();
            std::cout << "Pro Skills: ";
            std::getline(std::cin, pro_skill);
            exper = {id, fullname, birthday, phone, email, employee_type, cer, expln_year, pro_skill};
            ptr = std::make_unique<Experience> (exper);
            _manager_employees.insert(ptr);
            cer.clear();
            break;
        }
        else if(employee_type == FRESHER)
        {
            std::cout << "Employee type: Fresher" << std::endl;
            do{
                std::cout << "Graduation Date: ";
                std::getline(std::cin, graduation_date);
                try
                {
                    isValidDateFormat(graduation_date);
                    break;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            } while(true);
            std::cout << "Graduation Rank: ";
            std::getline(std::cin, graduation_rank);
            std::cout << "Education: ";
            std::getline(std::cin, education);
            fresh = {id, fullname, birthday, phone, email, employee_type, cer, graduation_date, graduation_rank, education};
            ptr = std::make_unique<Fresher> (fresh);
            _manager_employees.insert(ptr);
            cer.clear();
            break;
        }
        else if(employee_type == INTERN)
        {
            std::cout << "Employee type: Intern" << std::endl;
            std::cout << "Major: ";
            std::getline(std::cin, major);
            std::cout << "Semester: ";
            std::getline(std::cin, semester);
            std::cout << "University Name: ";
            std::getline(std::cin, university_name);
            intern = {id, fullname, birthday, phone, email, employee_type, cer, major, semester, university_name};
            ptr = std::make_unique<Intern> (intern);
            _manager_employees.insert(ptr);
            cer.clear();
            break;
        }
    } while (true);
}

void UI::ShowAll()
{
    _manager_employees.ShowAll();
}
void UI::findAllType()
{
    int employee_type;
    Manager ret;
    std::cout << "\n*** Search All of Type ***" << std::endl;
    do{
        std::cout << "Employee type (0-Experience, 1-Fresher, 2-Intern): ";
        std::cin >> employee_type;
        std::cin.ignore();
        if((employee_type == 0) || (employee_type == 1) || (employee_type == 2))
        {
            ret = _manager_employees.find_all_type(employee_type);
            std::cout << "Find all of type done!" << std::endl;
            ret.ShowAll();
            break;
        }
    } while (true);
}