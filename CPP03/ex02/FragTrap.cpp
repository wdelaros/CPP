#include "FragTrap.hpp"

FragTrap::FragTrap(const FragTrap &inst) : ClapTrap(inst)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = inst;
	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackPoint = 30;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoint < 1){
		std::cout << "FragTrap " + this->_name + " is already dead." << std::endl;
		return ;
	}
	else if (this->_energyPoint < 1){
		std::cout << "0 energy left. FragTrap " + this->_name + " cannot attacks." << std::endl;
		return ;
	}
	else
		std::cout << "FragTrap " + this->_name + " attacks " + target + ", causing " << this->_attackPoint << " points of damage!" << std::endl;
	this->_energyPoint--;
	std::cout << "FragTrap " + this->_name  + " has " << BLUE << this->_energyPoint << " energy points." << RESET << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (this->_hitPoint > 0)
		std::cout << "high fives" << std::endl;
	else
		std::cout << "FragTrap " + this->_name + " is dead" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap &FragTrap )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = FragTrap._name;
	this->_hitPoint = FragTrap._hitPoint;
	this->_attackPoint = FragTrap._attackPoint;
	this->_energyPoint = FragTrap._energyPoint;
	return *this;
}
