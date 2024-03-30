#ifndef _EXPERIENCE_H_
#define _EXPERIENCE_H_
#include"Employee.h"
class Experience : public Employee
{
private:
	float explnYear;
	std::string Proskill;
public:
	Experience() = default;
	Experience(std::string ID, std::string fullName, std::string birthday,
		std::string phone, std::string email, std::list<Certificate> cert,int type,
		float exYear, std::string Proskill);
	void setExYear(float years);
	void setProSkill(std::string skills);
	float getExYear();
	std::string getProSkill();
	void showInfo();
};
#endif // !_EXPERIENCE_H_


