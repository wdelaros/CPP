#pragma once

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( std::string name );
		FragTrap(const FragTrap &inst);
		~FragTrap( void );

		FragTrap& operator=( const FragTrap &FragTrap );

		void attack( const std::string& target );
		void highFivesGuys(void);
};