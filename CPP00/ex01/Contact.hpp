#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact{
	public:
		Contact(void);
		~Contact(void);

		void AddInfo(std::string p1, std::string p2, std::string p3, std::string p4, std::string p5);
		void ShowContact(int Number);
		void ShowInfo(void);

	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string _NumberPhone;
		std::string _DarkestSecret;
};

#endif