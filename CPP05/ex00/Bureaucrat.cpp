#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade){
	// std::cout << "Constructor called" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150) {
		throw GradeTooLowException();
	}
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat &inst ): _name(inst._name), _grade(inst._grade){
	*this = inst;
}

Bureaucrat::~Bureaucrat(){
	// std::cout << "Destructor called" << std::endl;
	return ;
}

std::string	Bureaucrat::getName(){
	return this->_name;
}

int	Bureaucrat::getGrade(){
	return this->_grade;
}

void	Bureaucrat::incrementGrade(){
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
	return ;
}

void	Bureaucrat::decrementGrade(){
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
	return ;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& inst){
	this->_grade = inst._grade;
	return *this;
}

const char *	Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

const char *	Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& rhs )
{
	return os << rhs.getName() << " bureaucrat grade " << rhs.getGrade();
}
