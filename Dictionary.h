#pragma once
class Dictionary : public std::map<std::string,Company>
{
public:
	Dictionary() {};

	bool IsCompanyExist(const std::string& company_name);
	bool IsFlightNumberExist(const std::string& company_name, unsigned int flight_number);

	void AddFlight(const std::string& company_name, unsigned int flight_number);
private:
	
};

