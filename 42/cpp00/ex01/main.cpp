#include <iostream>
#include <cstring>
#include <limits>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook book;
	std::string option;
	while (1)
	{
		std::cout << "You are running phone version 19.248\nEnter the command 'ADD' to add a new contact, 'SEARCH' to display a contact, or 'EXIT' to exit." << std::endl;
		std::cout << "\e[1;38;5;118mpromp$> \e[0m";
		std::getline(std::cin, option);
		if (std::cin.eof())
			break ;
		if (!option.compare("EXIT"))
			break ;
		if (!option.compare("ADD"))
			book.add_contact();
		if (option == "SEARCH")
		{
			book.display_contacts();
			book.find_contact();
		}
	}

	return (0);
}