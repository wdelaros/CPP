#include "Harl.hpp"

Harl::Harl( void )
{
	return ;
}

Harl::~Harl( void )
{
	return ;
}

void Harl::complain( std::string level )
{
	int value = 0;
	static std::string type[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (level == type[i])
			value = i + 1;

	switch (value) {
		case 1:
			std::cout << "[ DEBUG ]\nDinde Pomme Bacon Fromage suisse" << std::endl;
		case 2:
			std::cout << "[ INFO ]\nDinde Pomme Bacon" << std::endl;
		case 3:
			std::cout << "[ WARNING ]\nDinde Pomme" << std::endl;
		case 4:
			std::cout << "[ ERROR ]\nDinde" << std::endl;
			break ;
	}
}
