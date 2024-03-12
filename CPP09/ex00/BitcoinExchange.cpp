#include "BitcoinExchange.hpp"
#include <cctype>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange() {
	
}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::csv() {
	std::string line;
	std::ifstream db("data.csv");

	if (!db)
		throw std::invalid_argument("Error: could not open data.csv");
	std::getline(db, line);
	while (std::getline(db, line)) {
		unsigned long int i = line.find(",");
		std::string test = &line.data()[i + 1];
		line.erase(i, line.size());
		_csv.insert(std::pair<std::string, double>(line, std::stod(test)));
	}
	db.close();
}

void BitcoinExchange::inputFile(const char *file) {
	std::string line;
	double value;
	std::ifstream ifs(file);

	if (!ifs)
		throw std::invalid_argument("Error: could not open file");
	std::getline(ifs, line);
	if (line != "date | value")
		throw std::invalid_argument("Error: wrong format");
	while (std::getline(ifs, line)) {
		unsigned long long  int i = line.find(" | ");
		if (i == std::string::npos || countChar(line, ',') || countChar(line, '.') > 1)
			std::cout << "Error: bad input => " + line << std::endl;
		else {
			try {
				int skip = 0;
				std::string tmp = line.c_str() + i + 3;
				for (int j = 0; tmp[j]; j++) {
					if (!std::isdigit(tmp[j]) && tmp[j] != '.') {
						std::cout << "Error: bad input => " + line << std::endl;
						skip = 1;
						break ;
					}
				}
				if (skip)
					continue ;
				value = std::stod(&line.data()[i + 3]);
			} catch (std::exception & e) {
				std::cout << "Error: bad input => " + line << std::endl;
				continue ;
			}
			line.erase(i, line.size());
			if (!checkDate(line)) {
				std::cout << "Error: invalid date => " + line << std::endl;
				continue ;
			}
			else if (line < _csv.begin()->first) {
				std::cout << "Error: date must be greater than or equal to " + _csv.begin()->first << std::endl;
				continue ;
			}
			if (value < 0) {
				std::cout << "Error: not a positive number." << std::endl;
				continue ;
			}
			else if (value > 1000) {
				std::cout << "Error: too large a number." << std::endl;
				continue ;
			}
			_csvIter = _csv.begin();
			_csvIter++;
			if (_csv.begin()->first <= line && _csvIter->first > line) {
				std::cout << std::setprecision(10) << line << " => " << value << " = " << value * _csv.begin()->second << std::endl;
				continue ;
			}
			_csvIter = _csv.end();
			_csvIter--;
			while (_csvIter != _csv.begin()) {
				if (_csvIter->first <= line) {
					std::cout << std::setprecision(10) << line << " => " << value << " = " << value * _csvIter->second << std::endl;
					break ;
				}
				_csvIter--;
			}
			if (_csvIter->first <= line)
				continue ;
		}
	}
	ifs.close();
}