#pragma once

# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog( const Dog &inst );
		~Dog();

		void	makeSound() const;

		Dog& operator=( const Dog &inst );
};