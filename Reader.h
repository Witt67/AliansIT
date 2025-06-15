#pragma once

class Reader 
{
public:
	Reader(const std::string& input_file, const std::string& output_file);
	void operator() ();


private:
	auto CompanyCode(const std::string& flight) -> decltype(auto);
	auto FlightNumber(const std::string& company_code, const  std::string& flight) -> decltype(auto);
	
	std::string InputFileName;
	std::string OutputFileName;

	Dictionary  Dict;
};

