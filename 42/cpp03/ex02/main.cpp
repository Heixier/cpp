#include "ScavTrap.hpp"
#include <sstream>

static void	move(ScavTrap& protagonist, std::string input)
{
	std::string arg;
	std::istringstream	iss;
	unsigned int	value;

	if (input == "attack")
	{
		std::cout << "Attack target: ";
		std::getline(std::cin, arg);
		if (std::cin.eof())
		{
			std::cout << "oi\n";
			return;
		}
		protagonist.attack(arg);

	}
	else if (input == "ouch")
	{
		std::cout << "Damage taken: ";
		std::getline(std::cin, arg);
		if (std::cin.eof())
		{
			std::cout << "oi\n";
			return;
		}
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
		{
			std::cout << "oi\n";
			return;
		}
		iss.str(arg);
		iss >> value;
		if (iss.fail() || arg.length() <= 0)
		{
			std::cout << "Invalid number!\n";
			return;
		}
		protagonist.beRepaired(value);
	}
	else if (input == "guard")
	{
		protagonist.guardGate();
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
		return (std::cout << "oi\n", 0);
	ScavTrap scavtrap(input);

	while(true)
	{
		std::cout << "Enter a move: (attack), (ouch), (repair), (guard), (exit): ";
		std::getline(std::cin, input);
		if (input == "exit")
			return (std::cout << GREY << "Game end!\n", 0);
		if (std::cin.eof())
			return (std::cout << "oi\n", 0);
		move(scavtrap, input);
	}
	return (0);
}