#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* _brain;

	public:
		Cat();
		Cat( const Cat &inst );
		~Cat();

		void	makeSound() const;
		void	createIdea( std::string idea );
		void	printIdea( int i );

		Cat& operator=( const Cat &inst );
};