#include "ScavTrap.hpp"

int main(void){
	{
		ScavTrap *scav = new ScavTrap("papelipoupi");

		scav->attack("a");
		scav->takeDamage(20);
		scav->beRepaired(1);
		scav->guardGate();

		delete scav;
	}
	{
		ScavTrap *scav = new ScavTrap("papelipoupi");

		for (int i = 0;i < 50;i++)
			scav->beRepaired(50);
		scav->attack("a");

		delete scav;
	}
	{
		ScavTrap *scav = new ScavTrap("papelipoupi");

		scav->takeDamage(500);
		scav->guardGate();

		delete scav;
	}
	return 0;
}
