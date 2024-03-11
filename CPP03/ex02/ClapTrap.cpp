#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap &inst)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = inst;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoint(10), _energyPoint(10), _attackPoint(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoint < 1){
		std::cout << "ClapTrap " + this->_name + " is already dead." << std::endl;
		return ;
	}
	else if (this->_energyPoint < 1){
		std::cout << "0 energy left. ClapTrap " + this->_name + " cannot attacks." << std::endl;
		return ;
	}
	else
		std::cout << "ClapTrap " + this->_name + " attacks " + target + ", causing " << this->_attackPoint << " points of damage!" << std::endl;
	this->_energyPoint--;
	std::cout << "ClapTrap " + this->_name  + " has " << BLUE << this->_energyPoint << " energy points." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint < 1){
		std::cout << "ClapTrap " + this->_name + " is already dead." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " + this->_name + " take " << amount << " of damage." << std::endl;
	this->_hitPoint -= amount;
	if (this->_hitPoint < 1){
		std::cout << "ClapTrap " + this->_name + " is now dead." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " + this->_name + " has " << GREEN << this->_hitPoint << " life points" << RESET << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint < 1){
		std::cout << "ClapTrap " + this->_name + " is already dead." << std::endl;
		return ;
	}
	else if (this->_energyPoint < 1){
		std::cout << "0 energy left. ClapTrap " + this->_name + " cannot be repaired." << std::endl;
		return ;
	}
	else{
		this->_hitPoint += amount;
		std::cout << "ClapTrap " + this->_name + " was heal by " << amount << "." << std::endl;
	}
	this->_energyPoint--;
	std::cout << "ClapTrap " + this->_name + " has " << GREEN << this->_hitPoint << " life points " << RESET << "and " << BLUE << this->_energyPoint << " energy points." << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &ClapTrap )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = ClapTrap._name;
	this->_hitPoint = ClapTrap._hitPoint;
	this->_attackPoint = ClapTrap._attackPoint;
	this->_energyPoint = ClapTrap._energyPoint;
	return *this;
}
