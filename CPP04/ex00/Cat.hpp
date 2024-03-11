#pragma once

# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat( const Cat &inst );
		~Cat();

		void	makeSound() const;

		Cat& operator=( const Cat &inst );
};