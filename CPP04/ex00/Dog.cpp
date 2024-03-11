#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog( const Dog &inst )
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = inst._type;
	*this = inst;
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound() const
{
	std::cout << "woof" << std::endl;
}

Dog& Dog::operator=( const Dog &inst )
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	this->_type = inst._type;
	return *this;
}