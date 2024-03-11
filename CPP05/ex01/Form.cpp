#include "Form.hpp"

Form::Form( std::string name, int signGrade, int execGrade ): _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(0) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form( const Form& inst ): _name(inst._name), _signGrade(inst._signGrade), _execGrade(inst._execGrade), _isSigned(inst._isSigned) {
	*this = inst;
}

Form::~Form(){
	// std::cout << "Destructor called" << std::endl;
}

std::string	Form::getName(){
	return this->_name;
}

int	Form::getSignGrade(){
	return this->_signGrade;
}

int	Form::getExecGrade(){
	return this->_execGrade;
}

int	Form::getIsSigned(){
	return this->_isSigned;
}

void	Form::beSigned( Bureaucrat& bureaucrat ){
	if (bureaucrat.getGrade() <= getSignGrade())
		_isSigned = 1;
	else
		throw GradeTooLowException();
}

Form&	Form::operator=( const Form& inst ){
	this->_isSigned = inst._isSigned;
	return *this;
}

const char * Form::GradeTooHighException::what() const throw(){
	return "Form: Grade too high";
}

const char * Form::GradeTooLowException::what() const throw(){
	return "Form: Grade too low";
}

std::ostream& operator<<(std::ostream& os, Form& rhs ){
	return os << "	Form info" << std::endl \
	<< "Form: " << rhs.getName() << std::endl \
	<< "Sign: " << rhs.getIsSigned() << std::endl \
	<< "Sign grade require: " << rhs.getSignGrade() << std::endl \
	<< "Execution grade require: " << rhs.getExecGrade();
}