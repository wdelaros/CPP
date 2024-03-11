#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat( const Cat &inst )
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = inst._type;
	*this = inst;
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}

Cat& Cat::operator=( const Cat &inst )
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	this->_type = inst._type;
	return *this;
}