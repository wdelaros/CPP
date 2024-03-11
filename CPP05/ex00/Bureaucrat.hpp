#pragma once

# include <exception>
# include <string>
# include <iostream>


class Bureaucrat{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat( const Bureaucrat &inst );
		~Bureaucrat();

		std::string	getName();
		int			getGrade();

		void		incrementGrade();
		void		decrementGrade();

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