#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm("robotomy request", 72, 45), _target(target) {
	// std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& inst): AForm(inst), _target(inst._target) {
	*this = inst;
}

RobotomyRequestForm::~RobotomyRequestForm(){

}

std::string	RobotomyRequestForm::getTarget() const{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!getIsSigned())
		throw std::invalid_argument("Form isn't signed");
	if (executor.getGrade() > getSignGrade() || executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << "drill" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target <<  " has been robotomized" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& inst){
	this->_target = inst._target;
	return *this;
}