#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(void) : _name("Bob") { }

Zombie::Zombie(std::string new_name) : _name(new_name) { }

Zombie::~Zombie(void)
{
	std::cout << _name << "'s life subscription has expired!\n";
}
