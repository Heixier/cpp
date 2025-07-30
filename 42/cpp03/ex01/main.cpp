#include "ClapTrap.hpp"
#include <sstream>

static void	move(ClapTrap& protagonist, std::string input)
{
	std::string arg;
	std::istringstream	iss;
	unsigned int	value;

	if (input == "attack")
	{
		std::cout << "Attack target: ";
		std::getline(std::cin, arg);
		if (std::cin.eof())
			return;
		protagonist.attack(arg);

	}
	else if (input == "ouch")
	{
		std::cout << "Damage taken: ";
		std::getline(std::cin, arg);
		if (std::cin.eof())
			return;
		iss.str(arg);
		iss >> value;
		if (iss.fail() || arg.length() <= 0)
		{
			std::cout << "Invalid number!\n";
			return;
		}
		protagonist.takeDamage(value);
	}
	else if (input == "repair")
	{
		std::cout << "Damage repaired: ";
		std::getline(std::cin, arg);
		if (std::cin.eof())
			return;
		iss.str(arg);
		iss >> value;
		if (iss.fail() || arg.length() <= 0)
		{
			std::cout << "Invalid number!\n";
			return;
		}
		protagonist.beRepaired(value);
	}
	else
	{
		std::cout << "Invalid option!\n";
		return ;
	}
}

int main(void)
{
	std::string	input;

	std::cout << "Enter a name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return (0);
	ClapTrap claptrap(input);

	while(true)
	{
		std::cout << "Enter a move: (attack), (ouch), (repair), (exit): ";
		std::getline(std::cin, input);
		if (input == "exit" || std::cin.eof())
			break;
		move(claptrap, input);
	}
	return (0);
}