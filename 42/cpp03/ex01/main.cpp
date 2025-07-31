#include "ScavTrap.hpp"
#include <sstream>

static bool	ft_aredigits(const std::string& input) { return (input.find_first_not_of("0123456789") == std::string::npos ? true : false); }

static void	battle(ClapTrap& clappy, ScavTrap& scavvy, std::string& input)
{
	std::string arg;
	std::istringstream	iss;
	unsigned int	value;

	if (input == "attack")
	{
		scavvy.attack(clappy.get_name());
		if (scavvy.get_health() > 0)
		{
			clappy.takeDamage(scavvy.get_attack());
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
		if (iss.fail() || arg.length() <= 0 || !ft_aredigits(arg))
		{
			std::cout << "Invalid number!\n";
			return;
		}
		scavvy.takeDamage(value);
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
		if (iss.fail() || arg.length() <= 0 || !ft_aredigits(arg))
		{
			std::cout << "Invalid number!\n";
			return;
		}
		clappy.beRepaired(value);
		scavvy.beRepaired(value);
	}
	else if (input == "guard")
		scavvy.guardGate();
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
	if (!get_name("ScavTrap", input))
		return (0);
	ScavTrap	scavtrap(input);
	while(true)
	{
		std::cout << "Enter a move: (attack), (ouch), (repair), (guard), (exit): ";
		std::getline(std::cin, input);
		if (input == "exit")
			return (std::cout << GREY << "Game end!" << std::endl, 0);
		if (std::cin.eof())
			return (std::cout << "oi" << std::endl, 0);
		battle(claptrap, scavtrap, input);
	}
	return (0);
}