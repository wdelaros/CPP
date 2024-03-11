#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->_name = name;
	this->_weapon = NULL;
	return ;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}

HumanB::~HumanB( void )
{
	std::cout << "HumanB: Destructor called" << std::endl;
	return ;
}

void HumanB::attack( void )
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their hand" << std::endl;
	return ;
}
