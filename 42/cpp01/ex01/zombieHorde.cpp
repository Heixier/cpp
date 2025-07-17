#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie	*horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		horde[i].set_name(name);
		horde[i].set_size(n);
	}
	return (horde);
}

void	cancel_horde(Zombie *horde)
{
		delete[] horde;
}

void	anger_horde(Zombie *horde)
{
	int	horde_size = horde[0].get_size();

	std::cout << "Poking " << horde_size << " zombies with a stick...\n";
	for (int i = 0; i < horde_size; i++)
		horde[i].announce();
}