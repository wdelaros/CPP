#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	return ;
}

Brain::Brain( const Brain &inst )
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++){
		this->_ideas[i] = inst._ideas[i];
	}
	*this = inst;
	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

void Brain::setIdeas( std::string idea ){
	for (int i = 0; i < 100; i++) {
		if (this->_ideas[i].empty()){
			this->_ideas[i] = idea;
			return ;
		}
	}
	std::cout << "too many ideas" << std::endl;
}

std::string Brain::getIdeas( int i ){
	if (i < 0 || i > 99){
		std::cout << "Idea out of range!" << std::endl;
		return NULL;
	}
	else
		return this->_ideas[i];
}

Brain& Brain::operator=( const Brain &inst )
{
	std::cout << "Copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++){
		this->_ideas[i] = inst._ideas[i];
	}
	return *this;
}