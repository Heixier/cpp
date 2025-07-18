#include <iostream>
#include "Weapon.hpp"

int main(void)
{
	Weapon stick("Stick");
	std::cout << "Weapon name: " << stick.getType() << '\n';
	stick.setType("Pen");
	std::cout << "New weapon name: " << stick.getType() << '\n';

	return (0);
}