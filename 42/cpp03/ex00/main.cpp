#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Clap");
	
	ClapTrap	b = a;
	b.attack("hello");
	return (0);
}