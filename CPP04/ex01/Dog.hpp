#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain* _brain;

	public:
		Dog();
		Dog( const Dog &inst );
		~Dog();

		void	makeSound() const;
		void	createIdea( std::string idea);
		void	printIdea( int i );

		Dog& operator=( const Dog &inst );
};