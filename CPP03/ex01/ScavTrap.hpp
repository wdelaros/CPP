#pragma once

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( std::string name );
		ScavTrap(const ScavTrap &inst);
		~ScavTrap( void );

		void attack( const std::string& target );
		void guardGate();

		ScavTrap& operator=( const ScavTrap &ScavTrap );

	private:
		bool	_gateKeeper;
};