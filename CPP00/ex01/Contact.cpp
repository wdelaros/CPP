#include "Contact.hpp"

Contact::Contact(void){
	return ;
}

Contact::~Contact(void){
	return ;
}

void Contact::AddInfo(std::string p1, std::string p2, std::string p3, std::string p4, std::string p5){
	this->_FirstName = p1;
	this->_LastName = p2;
	this->_Nickname = p3;
	this->_NumberPhone = p4;
	this->_DarkestSecret = p5;
	return ;
}

void Contact::ShowContact(int Num){
	std::string First = this->_FirstName;
	std::string Last = this->_LastName;
	std::string Nick = this->_Nickname;

	std::cout << std::right << std::setw(10) << Num << "|";
	if (this->_FirstName.length() <= 10)
		std::cout << std::right << std::setw(10) << this->_FirstName << "|";
	else
		std::cout << std::right << std::setw(10) << First.replace(9, 1, ".").erase(10, First.length() - 10) << "|";
	if (this->_LastName.length() <= 10)
		std::cout << std::right << std::setw(10) << this->_LastName << "|";
	else
		std::cout << std::right << std::setw(10) << Last.replace(9, 1, ".").erase(10, Last.length() - 10) << "|";

	if (this->_Nickname.length() <= 10)
		std::cout << std::right << std::setw(10) << this->_Nickname << std::endl;
	else
		std::cout << std::right << std::setw(10) << Nick.replace(9, 1, ".").erase(10, Nick.length() - 10) << std::endl;
}

void Contact::ShowInfo(void){
	std::cout << "first name:	"; std::cout << this->_FirstName << std::endl;
	std::cout << "last name:	"; std::cout << this->_LastName << std::endl;
	std::cout << "nickname:	"; std::cout << this->_Nickname << std::endl;
	std::cout << "book number:	"; std::cout << this->_NumberPhone << std::endl;
	std::cout << "darkest secret:	"; std::cout << this->_DarkestSecret << std::endl;
}
