#include "ClapTrap.hpp"
#include <sstream>

static void	move(ClapTrap& protagonist, std::string input)
{
	std::string arg;
	std::istringstream	iss;
	unsigned int	value;

	if (input == "attack")
	{
		std::cout << "Attack who? ";
		std::getline(std::cin, arg);
		protagonist.attack(arg);

	}
	else if (input == "ouch")
	{
		std::cout << "Get hit for how much damage? ";
		std::getline(std::cin, arg);
		iss.str(arg);
		iss >> value;
		if (iss.fail() || arg.length() <= 0)
		{
			std::cout << "Invalid number!\n";
			return;
		}
		
		protagonist.takeDamage()

	}

}

int main(void)
{
	ClapTrap	claptrap("ClapTrap");
	std::string	input;

	while(input != "exit")
	{
		std::cout << "Enter a move (attack), (ouch), (repair): ";
		std::getline(std::cin, input);
		move(claptrap, input);
	}

	return (0);
}