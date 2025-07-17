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

static bool ft_arewhitespace(std::string str)
{
	return (str.find_first_not_of(' ') == str.npos);
}

void	PhoneBook::add_contact(void)
{
	std::string first_name, last_name, nick_name, phone_number, secret;

	first_name.clear();
	last_name.clear();
	nick_name.clear();
	phone_number.clear();
	secret.clear();

	while (first_name.empty())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
		if (std::cin.eof())
			return ;
		if (first_name.empty())
			continue;
		if (ft_arewhitespace(first_name))
		{
			first_name.clear();
			continue;
		}
	}

	while (last_name.empty())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
		if (std::cin.eof())
			return ;
		if (last_name.empty())
			continue;
		if (ft_arewhitespace(last_name))
		{
			last_name.clear();
			continue;
		}
	}

	while (nick_name.empty())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nick_name);
		if (std::cin.eof())
			return ;
		if (ft_arewhitespace(nick_name))
		{
			nick_name.clear();
			continue;
		}
	}
	
	while (phone_number.empty())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
		if (std::cin.eof())
			return;
		if (ft_arewhitespace(phone_number))
		{
			phone_number.clear();
			continue;
		}
		if (!ft_aredigits(phone_number))
		{
			std::cout << "Invalid phone number!\n";
			phone_number.clear();
			continue;
		}
		if (phone_number.length() < 8)
		{
			std::cout << "Phone number too short! (must be at least 8 digits)\n";
			phone_number.clear();
			continue;
		}
	}

	while (secret.empty())
	{
		std::cout << "Enter secret: ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
			return ;
		if (ft_arewhitespace(secret))
		{
			secret.clear();
			continue;
		}
	}

	this -> contact_list[contact_idx] = Contact(first_name, last_name, nick_name, phone_number, secret);
	this -> contact_idx = (this -> contact_idx + 1) % this -> max_contacts;
}

static std::string truncate(std::string string)
{
	if (string.length() > FMT_LEN)
		return (string.substr(0, 9) + '.');
	return (string);
}

void PhoneBook::display_contacts(void)
{
	if (contact_list[0].get_first_name().empty())
	{
		std::cout << "\e[38;5;196;1mPhonebook is empty!\033[0m\n";
		return ;
	}
	std::cout << std::left << std::setw(FMT_LEN * 4) << "\nPDF didn't ask for header so there's no header\n\n";
	for (size_t i = 0; i < max_contacts; i++)
	{
		if (contact_list[i].get_first_name().empty())
			continue;
		std::cout << ">> ";
		std::cout << std::right << std::setw(FMT_LEN) << i << '|'
		<< std::right << std::setw(FMT_LEN) << truncate(contact_list[i].get_first_name()) << '|' 
		<< std::right << std::setw(FMT_LEN) << truncate(contact_list[i].get_last_name()) << '|'
		<< std::right << std::setw(FMT_LEN) << truncate(contact_list[i].get_nick_name()) << " <<\n";
	}
	std::cout << '\n';
}

void	PhoneBook::find_contact(void)
{
	std::string	input;
	int	idx;

	if (contact_list[0].get_first_name().empty())
		return ;

	input.clear();
	while (input.empty())
	{
		std::cout << "Enter index of the entry to display: ";
		std::cin >> input;
		if (std::cin.eof())
			return ;
	}
	std::istringstream iss(input);

	iss >> idx;
	if (iss.fail() || input.length() != 1 || (size_t)idx >= max_contacts || contact_list[idx].get_first_name().empty())
	{
		std::cout << "Specified contact " << input << " is invalid or does not exist\n";
		return ;
	}
	std::cout << '\n';
	std::cout << "First name: " << contact_list[idx].get_first_name() << '\n';
	std::cout << "Last name: " << contact_list[idx].get_last_name() << '\n';
	std::cout << "Nickname: " << contact_list[idx].get_nick_name() << '\n';
	std::cout << "Phone number: " << contact_list[idx].get_phone_number() << '\n';
	std::cout << "Secret: " << contact_list[idx].get_secret() << '\n';
	std::cout << '\n';
}

PhoneBook::PhoneBook(void)
{
	this -> contact_idx = 0;
}

PhoneBook::~PhoneBook(void) { }
