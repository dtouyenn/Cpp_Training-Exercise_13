#ifndef _FRESHER_H_
#define _FREHSER_H_
#include"Employee.h"
class Fresher : public Employee 
{
private:
	std::string graDate;
	std::string graRank;
	std::string graEdu;
public:
	Fresher() = default;
	Fresher(std::string ID, std::string fullName, std::string birthday,
		std::string phone, std::string email, std::list<Certificate> cert, int type,
		std::string graDate, std::string graRank, std::string graEdu);
	void setGraDate(std::string date);
	void setGraRank(std::string rank);
	void setGraEdu(std::string edu);
	std::string getGraDate();
	std::string getGraRank();
	std::string getGraEdu();
	void showInfo();
};
#endif // !_FRESHER_H_

