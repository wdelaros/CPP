#include "Conversion.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return 1;
	Conversion c(argv[1]);
	c.setType();
	c.display();
	return 0;
}
