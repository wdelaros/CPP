#include "ClapTrap.hpp"

int main(void){
	{
		ClapTrap *clap = new ClapTrap("papelipoupi");

		clap->attack("a");
		clap->takeDamage(20);
		clap->beRepaired(1);

		delete clap;
	}
	{
		ClapTrap *clap = new ClapTrap("papelipoupi");

		for (int i = 0;i < 10;i++)
			clap->beRepaired(50);
		clap->attack("a");
		clap->takeDamage(500);
		clap->beRepaired(50);

		delete clap;
	}
	return 0;
}
