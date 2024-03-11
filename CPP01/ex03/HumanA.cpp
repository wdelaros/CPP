#include "HumanA.hpp"

HumanA::HumanA( std::string name , Weapon &weapon )
{
	this->_name = name;
	this->_weapon = &weapon;
	return ;
}

HumanA::~HumanA( void )
{
	std::cout << "HumanA: Destructor called" << std::endl;
	return ;
}

void HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}