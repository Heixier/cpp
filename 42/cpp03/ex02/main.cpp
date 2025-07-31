#include "FragTrap.hpp"
#include <sstream>

static void	battle(ClapTrap& clappy, FragTrap& fraggy, std::string& input)
{
	std::string arg;
	std::istringstream	iss;
	unsigned int	value;

	if (input == "attack")
	{
		fraggy.attack(clappy.get_name());
		if (fraggy.get_health() > 0)
		{
			clappy.takeDamage(fraggy.get_attack());
		}
	}
	else if (input == "ouch")
	{
		std::cout << "Damage taken: " << RED;
		std::getline(std::cin, arg);
		std::cout << END;
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
		fraggy.takeDamage(value);
	}
	else if (input == "repair")
	{
		std::cout << "Damage to repair: " << GREEN;
		std::getline(std::cin, arg);
		std::cout << END;
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
		clappy.beRepaired(value);
		fraggy.beRepaired(value);
	}
	else if (input == "five")
		fraggy.highFiveGuys();
	else
	{
		std::cout << "Invalid option!\n";
		return ;
	}
}

static bool get_name(const std::string& type, std::string &input)
{
	std::cout << type << " name: " << BLUE;
	std::getline(std::cin, input);
	std::cout << END;
	if (std::cin.eof())
		return (std::cout << "\noi" << std::endl, false);
	return (true);
}

int main(void)
{
	std::string	input;

	if (!get_name("ClapTrap", input))
		return (0);
	ClapTrap	claptrap(input);
	if (!get_name("FragTrap", input))
		return (0);
	FragTrap	FragTrap(input);
	while(true)
	{
		std::cout << "Enter a move: (attack), (ouch), (repair), (five), (exit): ";
		std::getline(std::cin, input);
		if (input == "exit")
			return (std::cout << GREY << "Game end!" << std::endl, 0);
		if (std::cin.eof())
			return (std::cout << "oi" << std::endl, 0);
		battle(claptrap, FragTrap, input);
	}
	return (0);
}