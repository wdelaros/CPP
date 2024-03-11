#include "Harl.hpp"

Harl::Harl( void )
{
	return ;
}

Harl::~Harl( void )
{
	return ;
}

void Harl::debug( void )
{
	std::cout << "Dinde Pomme Bacon Fromage suisse" << std::endl;
	return ;
}

void Harl::info( void )
{
	std::cout << "Dinde Pomme Bacon" << std::endl;
	return ;
}

void Harl::warning( void )
{
	std::cout << "Dinde Pomme" << std::endl;
	return ;
}

void Harl::error( void )
{
	std::cout << "Dinde" << std::endl;
	return ;
}

void Harl::complain( std::string level )
{
	static void ( Harl::*msg[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	static std::string type[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (level == type[i])
			(this->*msg[i])();
}
