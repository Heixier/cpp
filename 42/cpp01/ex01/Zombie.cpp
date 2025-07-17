#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string new_name)
{
	name = new_name;
}

void	Zombie::set_size(int size)
{
	_horde_size = size;
}

int	Zombie::get_size(void)
{
	return (_horde_size);
}

Zombie::Zombie(void) : name("Bob") { }

Zombie::Zombie(std::string new_name) : name(new_name), _horde_size(0) { }

Zombie::~Zombie(void)
{
	std::cout << name << "'s life subscription has expired!\n";
}
