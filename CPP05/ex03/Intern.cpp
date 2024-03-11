#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Intern::Intern() {

}

Intern::Intern(const Intern& inst) {
	*this = inst;
}

Intern::~Intern() {

}

Intern& Intern::operator=(const Intern& inst) {
	(void)inst;
	return *this;
}

AForm* Intern::makeForm(std::string fromName, std::string formTarget) {
	AForm* form = NULL;
	int value = 0;
	static std::string type[] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (fromName == type[i]) {
			value = i;
			break ;
		}
	}
	if (type[value] != fromName)
		value = 69;

	switch (value) {
		case 0:
			form = new RobotomyRequestForm(formTarget);
			break ;
		case 1:
			form = new PresidentialPardonForm(formTarget);
			break ;
		case 2:
			form = new ShrubberyCreationForm(formTarget);
			break ;
		default:
			throw std::invalid_argument("invalid form name");
			return NULL;
	}
	std::cout << "Intern creates " << fromName << std::endl;
	return form;
}
