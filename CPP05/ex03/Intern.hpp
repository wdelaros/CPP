#pragma once

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& inst);
		~Intern();

		Intern& operator=(const Intern& inst);

		AForm* makeForm(std::string fromName, std::string formTarget);
};
