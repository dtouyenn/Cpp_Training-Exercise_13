#ifndef _CERTIFICATE_H_
#define _CERTIFICATE_H_
#include<iostream>
#include<string>

class Certificate
{
private:
	std::string certificateID;
	std::string certificateName;
	std::string certificateRank;
	std::string certificateDate;
public:
	Certificate(std::string ID, std::string name, std::string rank, std::string date);
	void setCerID(std::string cerID);
	void setCerName(std::string cerName);
	void setCerRank(std::string cerRank);
	void setCerDate(std::string cerDate);
	std::string getCertID();
	std::string getCertName();
	std::string getCertRank();
	std::string getCertDate();
	std::string showCert();
};
#endif // !_CERTIFICATE_H_

