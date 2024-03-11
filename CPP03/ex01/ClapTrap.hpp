#pragma once

# include <string>
# include <iostream>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define DEFAULT	"\033[39m"
# define ERASE_LINE	"\033[2K\r"

class ClapTrap
{
	public:
		ClapTrap( std::string name );
		ClapTrap(const ClapTrap &inst);
		~ClapTrap( void );

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );

		ClapTrap& operator=( const ClapTrap &ClapTrap );

	protected:
		std::string _name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attackPoint;
};
