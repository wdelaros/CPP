#include "BitcoinExchange.hpp"
#include <iostream>
#include <map>
#include <string>

int countChar(std::string str, char c) {
	int	count = 0;

	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == c)
			count++;
	return count;
}

bool checkDate(std::string date) {
	std::map<int, int> dayMonth;
	int	year;
	int	month;
	int	day;

	if (countChar(date, '-') != 2)
		return false;
	if (date.size() - date.find_last_of("-") == 3)
		day = std::stoi(&date.data()[date.find_last_of("-") + 1]);
	else
		return false;
	date.erase(date.find_last_of("-"));
	if (date.size() - date.find_last_of("-") == 3)
		month = std::stoi(&date.data()[date.find_last_of("-") + 1]);
	else
		return false;
	date.erase(date.find_last_of("-"));
	if (date.size() == 4)
		year = std::stoi(date);
	else
		return false;
	dayMonth[1] = 31;
	if (year % 4)
		dayMonth[2] = 28;
	else
		dayMonth[2] = 29;
	dayMonth[3] = 31;
	dayMonth[4] = 30;
	dayMonth[5] = 31;
	dayMonth[6] = 30;
	dayMonth[7] = 31;
	dayMonth[8] = 31;
	dayMonth[9] = 30;
	dayMonth[10] = 31;
	dayMonth[11] = 30;
	dayMonth[12] = 31;
	if (day < 1 || month < 1 || month > 12 || year < 0 || day > dayMonth[month])
		return false;
	return true;
}

int main(int argc, char *argv[]) 
{
	if (argc < 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange bitcoin;

		bitcoin.csv();
		bitcoin.inputFile(argv[1]);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}