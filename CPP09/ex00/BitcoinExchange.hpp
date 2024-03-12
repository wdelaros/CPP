#pragma once

#include <map>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, double> _csv;
		std::map<std::string, double>::iterator _csvIter;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& inst);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& inst);

		void csv();
		void inputFile(const char *file);
};

int		countChar(std::string str, char c);
bool	checkDate(std::string date);