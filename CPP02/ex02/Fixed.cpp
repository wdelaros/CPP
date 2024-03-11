#include "Fixed.hpp"

Fixed::Fixed( void )
{
	// std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
	return ;
}

Fixed::Fixed( const Fixed &fixed )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return ;
}

Fixed::Fixed( const int fixedPointValue )
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumber = (fixedPointValue << this->_fractionnalBits);
	return ;
}

Fixed::Fixed( const float fixedPointNumber )
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumber = roundf(fixedPointNumber * (1 << this->_fractionnalBits));
	return ;
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed& Fixed::operator=( const Fixed& fixed )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_fixedPointNumber = fixed._fixedPointNumber;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed )
{
	return os << fixed.toFloat();
}

bool Fixed::operator>( const Fixed &fixed ) const
{
	return this->toFloat() > fixed.toFloat() ? true : false;
}

bool Fixed::operator<( const Fixed &fixed ) const
{
	return this->toFloat() < fixed.toFloat() ? true : false;
}

bool Fixed::operator>=( const Fixed &fixed ) const
{
	return this->toFloat() >= fixed.toFloat() ? true : false;
}

bool Fixed::operator<=( const Fixed &fixed ) const
{
	return this->toFloat() <= fixed.toFloat() ? true : false;
}

bool Fixed::operator==( const Fixed &fixed ) const
{
	return this->toFloat() == fixed.toFloat() ? true : false;
}

bool Fixed::operator!=( const Fixed &fixed ) const
{
	return this->toFloat() != fixed.toFloat() ? true : false;
}

Fixed Fixed::operator+( const Fixed &fixed )
{
	Fixed result;

	result.setRawBits(this->_fixedPointNumber + fixed._fixedPointNumber);
	return result;
}

Fixed Fixed::operator-( const Fixed &fixed )
{
	Fixed result;

	result.setRawBits(this->_fixedPointNumber - fixed._fixedPointNumber);
	return result;
}

Fixed Fixed::operator*( const Fixed &fixed )
{
	Fixed result;

	result.setRawBits(this->_fixedPointNumber * fixed.getRawBits() >> this->_fractionnalBits);
	return result;
}

Fixed Fixed::operator/( const Fixed &fixed )
{
	Fixed result;

	result.setRawBits(this->_fixedPointNumber * (1 << this->_fractionnalBits) / fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator++( int )
{
	Fixed copy = *this;
	++this->_fixedPointNumber;
	return copy;
}

Fixed	Fixed::operator++( void )
{
	++this->_fixedPointNumber;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed copy = *this;
	--this->_fixedPointNumber;
	return copy;
}

Fixed	Fixed::operator--( void )
{
	--this->_fixedPointNumber;
	return *this;
}

Fixed& Fixed::min(Fixed& nb1, Fixed& nb2)
{
	return ((nb1 < nb2) ? nb1 : nb2);
}

const Fixed& Fixed::min(const Fixed& nb1, const Fixed& nb2)
{
	return nb1 < nb2 ? nb1 : nb2;
}

Fixed& Fixed::max(Fixed& nb1, Fixed& nb2)
{
	return ((nb1 > nb2) ? nb1 : nb2);
}

const Fixed& Fixed::max(const Fixed& nb1, const Fixed& nb2)
{
	return nb1 > nb2 ? nb1 : nb2;
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