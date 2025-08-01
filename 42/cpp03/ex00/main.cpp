#include "ClapTrap.hpp"
#include <sstream>

static bool	ft_aredigits(const std::string& input) { return (input.find_first_not_of("0123456789") == std::string::npos ? true : false); }

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
		{
			std::cout << "oi\n";
			return;
		}
		protagonist.attack(arg);

	}
	else if (input == "ouch")
	{
		std::cout << "Damage to take: ";
		std::getline(std::cin, arg);
		if (std::cin.eof())
		{
			std::cout << "oi\n";
			return;
		}
		iss.str(arg);
		iss >> value;
		if (iss.fail() || arg.length() <= 0 || !ft_aredigits(arg))
		{
			std::cout << "Invalid number!\n";
			return;
		}
		protagonist.takeDamage(value);
	}
	else if (input == "repair")
	{
		std::cout << "Damage to repair: ";
		std::getline(std::cin, arg);
		if (std::cin.eof())
		{
			std::cout << "oi\n";
			return;
		}
		iss.str(arg);
		iss >> value;
		if (iss.fail() || arg.length() <= 0 || !ft_aredigits(arg))
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
		return (std::cout << "oi\n", 0);
	ClapTrap claptrap(input);
	ClapTrap clap_copy(claptrap);
	claptrap = clap_copy;

	while(true)
	{
		std::cout << "Enter a move: (attack), (ouch), (repair), (exit): ";
		std::getline(std::cin, input);
		if (input == "exit")
			return (std::cout << GREY << "Game end!\n", 0);
		if (std::cin.eof())
			return (std::cout << "oi\n", 0);
		move(claptrap, input);
	}
	return (0);
}