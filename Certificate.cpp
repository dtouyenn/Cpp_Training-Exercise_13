#include "Certificate.h"
Certificate::Certificate(std::string ID, std::string name, std::string rank, std::string date)
{
	this->certificateID = ID;
	this->certificateName = name;
	this->certificateRank = rank;
	this->certificateDate = date;
}
void Certificate::setCerID(std::string cerID) {
	this->certificateID = cerID;
}
void Certificate::setCerName(std::string cerName) {
	this->certificateName = cerName;
}
void Certificate::setCerRank(std::string cerRank) {
	this->certificateRank = cerRank;
}
void Certificate::setCerDate(std::string cerDate) {
	this->certificateDate = cerDate;
}
std::string Certificate::getCertID() {
	return certificateID;
}
std::string Certificate::getCertName() {
	return certificateName;
}
std::string Certificate::getCertRank() {
	return certificateRank;
}
std::string Certificate::getCertDate() {
	return certificateDate;
}

std::string Certificate::showCert()
{
	return "Certificate: " + certificateName + "\\" +
		"ID: " + certificateID + "\\" +
		"Rank: " + certificateRank + "\\" + 
		"Date: " + certificateDate + "\n";
}
