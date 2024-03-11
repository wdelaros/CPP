#include "Cat.hpp"
#include "Dog.hpp"

# define NBANIMAL 50

int main(void){
	{
		// const Animal* k = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		delete j;//should not create a leak
		delete i;
	}
	{
		const Animal *meta[NBANIMAL];

		for (int i = 0; i < NBANIMAL / 2; i++) {
			meta[i] = new Cat();
		}
		for (int i = NBANIMAL / 2; i < NBANIMAL; i++) {
			meta[i] = new Dog();
		}

		for (int i = 0; i < NBANIMAL; i++) {
			std::cout << i + 1 << ":	" << meta[i]->getType() << std::endl;
		}

		for (int i = 0; i < NBANIMAL; i++) {
			delete meta[i];
		}
	}
	return 0;
}