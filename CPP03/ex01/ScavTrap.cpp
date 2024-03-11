#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const ScavTrap &inst) : ClapTrap(inst)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = inst;
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name), _gateKeeper(false){
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackPoint = 20;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoint < 1){
		std::cout << "ScavTrap " + this->_name + " is already dead." << std::endl;
		return ;
	}
	else if (this->_energyPoint < 1){
		std::cout << "0 energy left. ScavTrap " + this->_name + " cannot attacks." << std::endl;
		return ;
	}
	else
		std::cout << "ScavTrap " + this->_name + " attacks " + target + ", causing " << this->_attackPoint << " points of damage!" << std::endl;
	this->_energyPoint--;
	std::cout << "ScavTrap " + this->_name  + " has " << BLUE << this->_energyPoint << " energy points." << RESET << std::endl;
}

void ScavTrap::guardGate( void ) {
	if (this->_hitPoint > 0){
		this->_gateKeeper = true;
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
	}
	else
		std::cout << "ScavTrap " + this->_name + " is dead" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &ScavTrap )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = ScavTrap._name;
	this->_hitPoint = ScavTrap._hitPoint;
	this->_attackPoint = ScavTrap._attackPoint;
	this->_energyPoint = ScavTrap._energyPoint;
	this->_gateKeeper = ScavTrap._gateKeeper;
	return *this;
}