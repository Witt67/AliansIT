#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <regex>

#include "Company.h"
#include "Dictionary.h"
#include "Reader.h"

std::regex company_name_template("(^([A-Z]{3}|[A-Z][A-Z0-9]\s?|[A-Z0-9][A-Z]\s?))");

Reader::Reader(const std::string& input_file, const std::string& output_file) : Dict() {
	InputFileName = input_file;
	OutputFileName = output_file;
}

auto Reader::CompanyCode(const std::string& flight) -> decltype(auto) {

	std::smatch m;

	if (std::regex_search(flight, m, company_name_template)) {
		return m.str();
	}

	return std::string();
}

auto Reader::FlightNumber(const std::string& company_code, const std::string& flight) -> decltype(auto) {
	auto pos = flight.begin() + company_code.size();
	while (*pos == ' ') ++pos;
	return flight.substr(*pos, std::string::npos);
}

void Reader::operator () ()
{
	std::ifstream inp_file(this->InputFileName);
	if (!inp_file.is_open())
		return;

	std::string line;
	while (std::getline(inp_file, line))
	{
		if (!line.empty())
		{
			auto company_name = this->CompanyCode(line);
			auto pos = company_name.size();
			auto flight_number = std::stoi(line.substr(pos));
			this->Dict.AddFlight(company_name, flight_number);
		}
	}

	std::ofstream out_file(this->OutputFileName);
	if (!out_file.is_open())
		return;

	for (const auto& [company_name, company] : this->Dict)
	{
		for (const auto& flights : company) {
			if (company_name.size() < 3)
				out_file << company_name << " " << flights << std::endl;
			else 
				out_file << company_name << flights << std::endl;
		}
	}
	out_file.close();
}

