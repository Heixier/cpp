#include <iostream>
#include <sstream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name);
void	cancel_horde(Zombie *horde);
void	anger_horde(Zombie *horde);

int main(void)
{
	Zombie* 	horde;
	std::string	input_number;
	std::string	input_name;
	int			num_zombies;

	std::cout << "Zombie lab 01:\n";

	std::cout << "Enter number of zombies to spawn: ";
	std::getline(std::cin, input_number);

	std::istringstream iss(input_number);
	iss >> num_zombies;
	if (iss.fail() || input_number.length() <= 0 || num_zombies < 0)
	{
		std::cout << "Invalid number \'" << input_number << "\'!\n";
		return (1);
	}
	std::cout << "num zombies: " << input_number << std::endl;
	std::cout << "Enter name for horde: ";
	std::cin >> std::ws >> input_name;
	horde = zombieHorde(num_zombies, input_name);
	anger_horde(horde);
	cancel_horde(horde);
}
