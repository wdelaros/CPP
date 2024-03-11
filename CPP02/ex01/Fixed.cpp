#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
	return ;
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return ;
}

Fixed::Fixed( const int fixedPointValue )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumber = (fixedPointValue << this->_fractionnalBits);
	return ;
}

Fixed::Fixed( const float fixedPointNumber )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumber = roundf(fixedPointNumber * (1 << this->_fractionnalBits));
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed& Fixed::operator=( const Fixed& fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_fixedPointNumber = fixed._fixedPointNumber;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed )
{
	return os << fixed.toFloat();
}

float Fixed::toFloat( void ) const
{
	return (float)this->_fixedPointNumber / (float)(1 << this->_fractionnalBits);
}

int Fixed::toInt( void ) const
{
	return this->_fixedPointNumber >> this->_fractionnalBits;
}

int Fixed::getRawBits( void ) const
{
	return this->_fixedPointNumber;
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPointNumber = raw;
	return ;
}