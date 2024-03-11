#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

Animal::Animal( const Animal &inst )
{
	std::cout << "Animal Copy constructor called" << std::endl;
	this->_type = inst._type;
	*this = inst;
	return ;
}


Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{

}

Animal& Animal::operator=( const Animal &inst )
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	this->_type = inst._type;
	return *this;
}
