#include <map>
#include <set>
#include <string>

#include "Company.h"
#include "Dictionary.h"

bool Dictionary::IsCompanyExist(const std::string& company_name) {
	return (this->find(company_name) != this->end());
}

bool Dictionary::IsFlightNumberExist(const std::string& company_name, unsigned int flight_number) {
	return this->IsCompanyExist(company_name) && this->operator[](company_name).IsFlightNumberExist(flight_number);
}

void Dictionary::AddFlight(const std::string& company_name, unsigned int flight_number) {
	if (this->IsCompanyExist(company_name)) {
		this->operator[](company_name).insert(flight_number);
	}
	else {
		Company company;
		company.insert(flight_number);
		this->operator[](company_name) = company;
	}
}