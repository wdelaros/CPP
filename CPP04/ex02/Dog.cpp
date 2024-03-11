#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog( const Dog &inst ){
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = inst._type;
	this->_brain = new Brain(*inst._brain);
	*this = inst;
	return ;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return ;
}

void	Dog::makeSound() const{
		std::cout << "woof" << std::endl;
}

void	Dog::createIdea( std::string idea ){
	this->_brain->setIdeas(idea);
}

void	Dog::printIdea( int i ){
	if (i < 0 || i > 99){
		std::cout << "Idea out of range!" << std::endl;
		return ;
	}
	std::cout << this->_brain->getIdeas(i) << std::endl;
}

Dog& Dog::operator=( const Dog &inst ){
	std::cout << "Dog Copy assignment operator called" << std::endl;
	this->_type = inst._type;
	*this->_brain = *inst._brain;
	return *this;
}