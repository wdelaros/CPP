#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string	input;
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string NumberPhone;
	std::string DarkestSecret;
	int	ContactNumber = 0;

	while (std::cout << "input:	" && std::getline(std::cin, input))
	{
		if (input == "ADD")
		{
			std::cout << "first name:	"; std::getline(std::cin, FirstName);
			std::cout << "last name:	"; std::getline(std::cin, LastName);
			std::cout << "nickname:	"; std::getline(std::cin, Nickname);
			std::cout << "book number:	"; std::getline(std::cin, NumberPhone);
			std::cout << "darkest secret:	"; std::getline(std::cin, DarkestSecret);
			if (!FirstName.length() || !LastName.length() || !Nickname.length() || !NumberPhone.length() || !DarkestSecret.length())
				std::cout << "Incorrect data" << std::endl;
			else 
			{
				book.Add(FirstName, LastName, Nickname, NumberPhone, DarkestSecret, (ContactNumber % 8));
				ContactNumber++;
			}
		}
		else if (input == "SEARCH")
		{
			if (ContactNumber == 0)
				std::cout << "No contact register" << std::endl;
			else
			{
				if (ContactNumber < 8)
				{
					for (int i = 0; i < ContactNumber % 8 && ContactNumber != 0; i++)
						book.ShowContact(i);
				}
				else
					for (int i = 0; i < 8; i++)
						book.ShowContact(i);
				std::cout << "enter an index:	";
				std::getline(std::cin, input);
				if (input.length() > 1 || !std::isdigit(input[0]) || std::stoi(input, 0, 10) > 7)
					std::cout << "Out of range" << std::endl;
				else if (std::stoi(input, 0, 10) >= ContactNumber % 8)
					std::cout << "Wrong index" << std::endl;
				else
					book.ShowInfo(std::stoi(input, 0, 10));
			}
		}
		else if (input == "EXIT")
			break ;
	}
}
