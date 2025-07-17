#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(void) : name("Bob") { }

Zombie::Zombie(std::string new_name) : name(new_name) { }

Zombie::~Zombie(void)
{
	std::cout << name << "'s life subscription has expired!\n";
}
