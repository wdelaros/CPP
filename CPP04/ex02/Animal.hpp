#pragma once

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal( const Animal &inst );
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() const = 0;

		Animal& operator=( const Animal &inst );
};