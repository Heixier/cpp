#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string new_name)
{
	_name = new_name;
}

void	Zombie::set_size(int size)
{
	_horde_size = size;
}

int	Zombie::get_size(void)
{
	return (_horde_size);
}

Zombie::Zombie(void) : _name("Bob") { }

Zombie::Zombie(std::string new_name) : _name(new_name), _horde_size(0) { }

Zombie::~Zombie(void)
{
	std::cout << _name << " has died (again)\n";
}
