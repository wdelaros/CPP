#pragma once

# include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;

		public:
			AForm();
			AForm( std::string name, int signGrade, int execGrade );
			AForm( const AForm& inst );
			virtual ~AForm();

			const std::string	getName() const;
			int					getSignGrade() const;
			int					getExecGrade() const;
			int					getIsSigned() const;

			void				beSigned( Bureaucrat& bureaucrat );

			virtual void		execute(Bureaucrat const & executor) const = 0;

			AForm& operator=( const AForm& inst );

			class GradeTooHighException: public std::exception{
				public:
					const char * what() const throw();
			};
			class GradeTooLowException: public std::exception{
				public:
					const char * what() const throw();
			};
};

std::ostream& operator<<( std::ostream& os, AForm& rhs );
