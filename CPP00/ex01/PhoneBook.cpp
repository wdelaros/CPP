#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	return ;
}

PhoneBook::~PhoneBook(void){
	return ;
}

void PhoneBook::Add(std::string p1, std::string p2, std::string p3, std::string p4, std::string p5, int Num){
	this->_contacts[Num ].AddInfo(p1, p2, p3, p4, p5);
	return ;
}

void PhoneBook::ShowContact(int Num){
	this->_contacts[Num].ShowContact(Num);
	return ;
}

void PhoneBook::ShowInfo(int Num){
	this->_contacts[Num].ShowInfo();
	return ;
}