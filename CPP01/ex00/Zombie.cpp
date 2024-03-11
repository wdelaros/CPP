#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return ;
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << ": Destructor called" << std::endl;
	return ;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}