#include "RPN.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: invalid number of argument" << std::endl;
		return 1;
	}

	MutantStack<double> container;
	std::string test = argv[1];
	unsigned long index;
	int	countDigit = 0;
	int	countOperator = 0;

	while ((index = test.find_first_not_of(" ")) != std::string::npos) {
		if ((!isdigit(test[index]) && countDigit < 2) || (test[index] != '+' && test[index] != '-' && test[index] != '/' \
		&& test[index] != '*' && test[index + 1] != ' ' && test[index + 1] != '\0')) {
			std::cout << "Error: invalid character" << std::endl;
			return 1;
		}
		if (isdigit(test[index]))
			countDigit++;
		else {
			countOperator++;
			if (countOperator >= countDigit) {
				std::cout << "Error: invalid RPN" << std::endl;
				return 1;
			}
		}
		if (isdigit(test[index]))
			container.push(test[index] - 48);
		else
			container.push(test[index] + 0.5);
		test.erase(0, index + 1);
	}
	if (countOperator + 1 != countDigit || countDigit < 2) {
		std::cout << "Error: invalid number of character" << std::endl;
		return 1;
	}

	MutantStack<double> tmp;

	int result = 0;
	bool transfer;

	MutantStack<double>::container_type::iterator it;
	for (size_t i = 0; i < container.size(); i++) {
		transfer = true;
		it = container.begin();
		if (it[i] == '+' + 0.5)
			result = it[i - 2] + it [i - 1];
		else if (it[i] == '-' + 0.5)
			result = it[i - 2] - it [i - 1];
		else if (it[i] == '/' + 0.5) {
			if (it [i - 1] == 0) {
				std::cout << "can't divide by 0" << std::endl;
				return 1;
			}
			result = it[i - 2] / it [i - 1];
		}
		else if (it[i] == '*' + 0.5)
			result = it[i - 2] * it [i - 1];
		else
			transfer = false;
		if (transfer) {
			for (size_t j = 0; j < i - 2; j++)
				tmp.push(it[j]);
			tmp.push(result);
			for (size_t j = i + 1; j < container.size(); j++)
				tmp.push(it[j]);
			container.swap(tmp);
			while (!tmp.empty())
				tmp.pop();
			if (container.size() < 3)
				break ;
			i = 0;
		}
	}
	std::cout << result << std::endl;
}