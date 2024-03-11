#pragma once

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal &inst );
		virtual ~WrongAnimal();

		std::string	getType() const;
		virtual void	makeSound() const;

		WrongAnimal&	operator=( const WrongAnimal &inst );
};