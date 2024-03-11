#pragma once

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		std::string	_target;

	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& inst );
		~PresidentialPardonForm();

		std::string		getTarget() const;

		virtual void	execute(Bureaucrat const & executor) const;

		PresidentialPardonForm& operator=( const PresidentialPardonForm& inst);
};
