#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie* new_zombie;

	std::cout << "Zombie lab 00:\n";

	new_zombie = newZombie("Bob");
	new_zombie->announce();
	randomChump("Steve");
	delete new_zombie;
}
