#include "AForm.hpp"

AForm::AForm(): _signGrade(150), _execGrade(150) {
	// std::cout << "Default constructor called" << std::endl;
}

AForm::AForm( std::string name, int signGrade, int execGrade ): _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(0) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm& inst ): _name(inst._name), _signGrade(inst._signGrade), _execGrade(inst._execGrade), _isSigned(inst._isSigned) {
	*this = inst;
}

AForm::~AForm(){
	// std::cout << "Destructor called" << std::endl;
}

const std::string	AForm::getName() const {
	return this->_name;
}

int	AForm::getSignGrade() const {
	return this->_signGrade;
}

int	AForm::getExecGrade() const {
	return this->_execGrade;
}

int	AForm::getIsSigned() const {
	return this->_isSigned;
}

void	AForm::beSigned( Bureaucrat& bureaucrat ){
	if (bureaucrat.getGrade() <= getSignGrade())
		_isSigned = 1;
	else
		throw GradeTooLowException();
}

AForm&	AForm::operator=( const AForm& inst ){
	this->_isSigned = inst._isSigned;
	return *this;
}

const char * AForm::GradeTooHighException::what() const throw(){
	return "AForm: Grade too high";
}

const char * AForm::GradeTooLowException::what() const throw(){
	return "AForm: Grade too low";
}

std::ostream& operator<<(std::ostream& os, AForm& rhs ){
	return os << "	AForm info" << std::endl \
	<< "AForm: " << rhs.getName() << std::endl \
	<< "Sign: " << rhs.getIsSigned() << std::endl \
	<< "Sign grade require: " << rhs.getSignGrade() << std::endl \
	<< "Execution grade require: " << rhs.getExecGrade() << std::endl;
}