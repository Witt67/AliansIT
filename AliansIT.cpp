// AliansIT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <map>
#include <set>

#include "Company.h"
#include "Dictionary.h"
#include "Reader.h"

/*std::regex company_name_template("(^(|[A-Z]{3}|[A-Z][A-Z0-9]|[A-Z0-9][A-Z]))");


std::string_view CompanyCode(const std::string& flight) {

    std::string_view result{""};

    if (isalpha(flight[0]))
    {
        if (isdigit(flight[1])) {
            result = flight.substr(2);
        }
        else if (isalpha(flight[1])) {
            result = (isalpha(flight[2]) ? flight.substr(3) : flight.substr(2));
        }
    }
    else if (isdigit(flight[0]) && isalpha(flight[1]))
        result = flight.substr(2);

    return result;
}

*/

class ThreadGuard
{
private:
    std::thread& Thread;
public:
    explicit ThreadGuard (std::thread& thr) : Thread(thr) {}

    ~ThreadGuard()
    {
        if (Thread.joinable())
        {
            Thread.join();
        }
    }
    ThreadGuard(ThreadGuard const&) = delete;
    ThreadGuard& operator=(ThreadGuard const&) = delete;
};



int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "The right format of running this application is:" << std::endl;
        std::cout << "AliansIT <1_in.txt> <2_in.txt> ...  <N_in.txt>" << std::endl;
        std::cout << "Example:" << std::endl;
        std::cout << "AliansIT 1_in.txt 2_in.txt" << std::endl;
        return 1;
    }

    for (auto i = 1; i < argc; ++i)
    {
        auto data_set_number = std::stoi(argv[i]);
        Reader reader(argv[i], std::to_string(data_set_number) + "_out.txt");
        std::thread thr(reader);
        ThreadGuard guard(thr);
    }
}
