#include "Fresher.h"

Fresher::Fresher(std::string ID, std::string fullName, std::string birthday, 
	std::string phone, std::string email, std::list<Certificate> cert, int type, 
	std::string graDate, std::string graRank, std::string graEdu) : Employee(ID, fullName, birthday, phone, email, cert, type)
{
	this->graDate = graDate;
	this->graRank = graRank;
	this->graEdu = graEdu;
}

void Fresher::setGraDate(std::string date)
{
	this->graDate = date;
}

void Fresher::setGraRank(std::string rank)
{
	this->graRank = rank;
}

void Fresher::setGraEdu(std::string edu)
{
	this->graEdu = edu;
}

std::string Fresher::getGraDate()
{
	return graDate;
}

std::string Fresher::getGraRank()
{
	return graRank;
}

std::string Fresher::getGraEdu()
{
	return graEdu;
}

void Fresher::showInfo()
{
	std::cout << "Employee ID: " + ID + "\n" +
		"Full name: " + fullName + "\n" +
		"Date of birth: " + birthDay + "\n" +
		"Phone: " + phone + "\n" +
		"Email: " + email + "\n" +
		"Graduation date: " + graDate + "\n" +
		"Graduation rank: " + graRank + "\n" +
		"Education: " + graEdu + "\n" +
		"------Certificate------" + "\n" +
		showCert(cert);
}

