#pragma once

# include "AForm.hpp"
# include <fstream>


class ShrubberyCreationForm: public AForm{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& inst );
		~ShrubberyCreationForm();

		std::string		getTarget() const;

		virtual void	execute(Bureaucrat const & executor) const;

		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& inst );
};