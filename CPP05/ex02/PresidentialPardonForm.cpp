#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("presidential pardon", 25, 5), _target(target) {
	// std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& inst ): AForm(inst), _target(inst._target) {
	*this = inst;
}

PresidentialPardonForm::~PresidentialPardonForm(){

}

std::string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw std::invalid_argument("Form isn't signed");
	if (executor.getGrade() > getSignGrade() || executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& inst){
	this->_target = inst._target;
	return *this;
}
