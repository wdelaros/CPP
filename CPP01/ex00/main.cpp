#include "Zombie.hpp"

int main( void )
{
	Zombie *will;
	Zombie *raph;
	Zombie *zach;

	will = newZombie("will");
	raph = newZombie("raph");
	zach = newZombie("zach");

	randomChump("william");

	will->announce();
	raph->announce();
	zach->announce();

	delete will;
	delete raph;
	delete zach;
}
