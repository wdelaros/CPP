#include "PmergeMe.hpp"

bool parseArgument(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (!argv[i][0])
			return false;
		for (int j = 0; argv[i][j]; j++)
			if (!std::isdigit(argv[i][j]))
				return false;
	}
	return true;
}

void print(int argc, char *argv[]) {
	std::cout << "Before:	";
	for (int i = 1; i < argc; i++)
		std::cout << std::atoi(argv[i]) << " ";
	std::cout << std::endl;
}

void print(std::chrono::duration<double> timer, int argc, std::string str) {
	std::cout << "Time to process a range of	" << argc - 1 << " elements with std::";
	std::cout << str << ":	" << std::fixed << std::setprecision(10) << timer.count() << std::endl;
}