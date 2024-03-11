#pragma once

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat( const WrongCat &inst );
		~WrongCat();

		void	makeSound() const;

		WrongCat& operator=( const WrongCat &inst );
};