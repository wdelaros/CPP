#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal &inst )
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	this->_type = inst._type;
	*this = inst;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::makeSound() const
{

}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &inst )
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	this->_type = inst._type;
	return *this;
}