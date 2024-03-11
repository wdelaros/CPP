#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	{
		FragTrap *frag = new FragTrap("papelipoupi");

		frag->attack("a");
		frag->takeDamage(20);
		frag->beRepaired(1);
		frag->highFivesGuys();

		delete frag;
	}
	{
		FragTrap *frag = new FragTrap("papelipoupi");

		for (int i = 0;i < 100;i++)
			frag->beRepaired(50);
		frag->attack("a");
		frag->highFivesGuys();

		delete frag;
	}
	{
		FragTrap *frag = new FragTrap("papelipoupi");

		frag->takeDamage(100);
		frag->highFivesGuys();

		delete frag;
	}
	return 0;
}
