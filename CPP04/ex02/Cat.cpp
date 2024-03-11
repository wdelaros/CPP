#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	return ;
}

Cat::Cat( const Cat &inst ){
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = inst._type;
	this->_brain = new Brain(*inst._brain);
	*this = inst;
	return ;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return ;
}

void	Cat::makeSound() const{
	std::cout << "meow" << std::endl;
}

void	Cat::createIdea( std::string idea ){
	this->_brain->setIdeas(idea);
}

void	Cat::printIdea( int i ){
	if (i < 0 || i > 99){
		std::cout << "Idea out of range!" << std::endl;
		return ;
	}
	std::cout << this->_brain->getIdeas(i) << std::endl;
}

Cat& Cat::operator=( const Cat &inst ){
	std::cout << "Cat Copy assignment operator called" << std::endl;
	this->_type = inst._type;
	*this->_brain = *inst._brain;
	return *this;
}