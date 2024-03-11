#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->_type = type;
	return ;
}

Weapon::~Weapon( void )
{
	std::cout << "Weapon: Destructor called" << std::endl;
	return ;
}

const std::string &Weapon::getType( void ) const
{
	return this->_type;
}

void Weapon::setType( std::string type )
{
	this->_type = type;
	return ;
}