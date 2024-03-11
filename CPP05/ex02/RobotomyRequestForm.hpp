#pragma once

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		std::string	_target;

	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& inst );
		~RobotomyRequestForm();

		std::string		getTarget() const;

		virtual void	execute(Bureaucrat const & executor) const;

		RobotomyRequestForm& operator=(const RobotomyRequestForm& inst);
};