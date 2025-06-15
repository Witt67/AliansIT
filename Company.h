#pragma once

class Company : public std::set<unsigned int>
{
public:
	bool IsFlightNumberExist(unsigned int flight_number);
	bool IsFlightNumberExist(std::string const& flight_number);
private:
};

