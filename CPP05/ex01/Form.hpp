#pragma once

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;

		public:
			Form( std::string name, int signGrade, int execGrade );
			Form( const Form& inst );
			~Form();

			std::string	getName();
			int			getSignGrade();
			int			getExecGrade();
			int			getIsSigned();

			void		beSigned( Bureaucrat& bureaucrat );

			Form& operator=( const Form& inst );

			class GradeTooHighException: public std::exception{
				public:
					const char * what() const throw();
			};
			class GradeTooLowException: public std::exception{
				public:
					const char * what() const throw();
			};
};

std::ostream& operator<<( std::ostream& os, Form& rhs );
