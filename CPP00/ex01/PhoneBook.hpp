#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void Add(std::string p1, std::string p2, std::string p3, std::string p4, std::string p5, int Num);
		void ShowContact(int Num);
		void ShowInfo(int Num);

	private:
		Contact _contacts[8];
};

#endif