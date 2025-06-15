#include <set>
#include <string>

#include "Company.h"

bool Company::IsFlightNumberExist(unsigned int flight_number) {
	return (find(flight_number) != end());
}

bool Company::IsFlightNumberExist(std::string const& flight_number) {
	return (find(std::stoi(flight_number)) != end());
}