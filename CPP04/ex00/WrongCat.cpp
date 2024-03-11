#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &inst )
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	this->_type = inst._type;
	*this = inst;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "minouminouminouminouminouminouminou" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat &inst )
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	this->_type = inst._type;
	return *this;
}
