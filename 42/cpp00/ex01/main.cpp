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
		std::cout << "You are running phone version 153.28\nEnter the command 'ADD' to add a new contact, 'SEARCH' to display a contact, or 'EXIT' to exit." << std::endl;
		std::cin >> std::ws >> option;
		if (std::cin.eof())
			break ;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (!option.compare("EXIT"))
			break ;
		if (!option.compare("ADD"))
			book.add_contact();
		if (!option.compare("SEARCH"))
		{
			book.display_contacts();
			book.find_contact();
		}
	}

	return (0);
}