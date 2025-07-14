#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static bool ft_aredigits(std::string str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

void	PhoneBook::add_contact(void)
{
	std::string first_name, last_name, nick_name, phone_number, secret;

	std::cout << "Enter first name: ";
	std::cin >> std::ws >> first_name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter last name: ";
	std::cin >> std::ws >> last_name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nick_name);

	std::cout << "Enter phone number: ";
	std::cin >> std::ws >> phone_number;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (!ft_aredigits(phone_number))
	{
		std::cout << "Invalid phone number!\n";
		return ;
	}
	if (phone_number.length() < 8)
	{
		std::cout << "Phone number too short! (must be at least 8 digits)\n";
		return ;
	}

	std::cout << "Enter secret: ";
	std::getline(std::cin, secret);

	this -> contact_list[contact_idx] = Contact(first_name, last_name, nick_name, phone_number, secret);
	std::cout << "Added contact number: " << contact_idx << '\n';
	this -> contact_idx = (this -> contact_idx + 1) % this -> max_contacts;
}

static std::string truncate(std::string string)
{
	if (string.length() >= FMT_LEN)
		return (string.substr(0, 9) + '.');
	return (string);
}

void PhoneBook::display_contacts(void)
{
	for (size_t i = 0; i < max_contacts; i++)
	{
		if (contact_list[i].get_first_name().empty())
			continue;
		std::cout << std::right << std::setw(FMT_LEN) << i << '|' 
		<< std::right << std::setw(FMT_LEN) << truncate(contact_list[i].get_first_name()) << '|' 
		<< std::right << std::setw(FMT_LEN) << truncate(contact_list[i].get_last_name()) << '|'
		<< std::right << std::setw(FMT_LEN) << truncate(contact_list[i].get_nick_name()) << '\n';
	}
}

void	PhoneBook::find_contact(void)
{
	std::string	input;
	int	idx;

	if (contact_list[0].get_first_name().empty())
	{
		std::cout << "Phonebook is empty!\n";
		return ;
	}
	std::cout << "Enter index of the entry to display: ";
	std::cin >> input;
	std::istringstream iss(input);

	iss >> idx;
	if (iss.fail() || input.length() != 1 || (size_t)idx >= max_contacts || contact_list[idx].get_first_name().empty())
	{
		std::cout << "Specified contact " << input << " is invalid or does not exist\n";
		return ;
	}
	std::cout << contact_list[idx].get_first_name() << '\n';
	std::cout << contact_list[idx].get_last_name() << '\n';
	std::cout << contact_list[idx].get_nick_name() << '\n';
	std::cout << contact_list[idx].get_phone_number() << '\n';
	std::cout << contact_list[idx].get_secret() << '\n';
}

PhoneBook::PhoneBook(void)
{
	this -> contact_idx = 0;
}

PhoneBook::~PhoneBook(void) { }
