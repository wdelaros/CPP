#pragma once

# include <exception>
# include <string>
# include <iostream>

#include "AForm.hpp"
class AForm;

class Bureaucrat{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat( const Bureaucrat& inst );
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

		void				signForm(AForm& aForm);
		void				executeForm(AForm const & aForm);

		Bureaucrat&	operator=( const Bureaucrat& inst);

		class GradeTooLowException: public std::exception{
			public:
				const char * what() const throw();
		};
		class GradeTooHighException: public std::exception{
			public:
				const char * what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, Bureaucrat& rhs );