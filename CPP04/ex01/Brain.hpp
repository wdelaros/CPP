#pragma once

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain( const Brain &inst );
		~Brain();

		std::string getIdeas( int i );
		void setIdeas( std::string idea );

		Brain& operator=( const Brain &inst );
};