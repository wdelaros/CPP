#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try {
		Bureaucrat bureaucrat("allo", 151);
		std::cout << bureaucrat << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("allo", 150);
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("allo", 0);
		std::cout << bureaucrat << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("allo", 1);
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("allo", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}