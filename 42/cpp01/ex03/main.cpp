#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon stick("Stick");
	Weapon gun("M4A1");
	HumanA bob("Bob", stick);

	bob.attack();
	stick.setType("Pen");
	bob.attack();

	HumanB sam("Sam");
	sam.setWeapon(&stick);
	sam.attack();
	stick.setType("Sword");
	sam.attack();
	sam.setWeapon(&gun);
	sam.attack();
	bob.attack();

	return (0);
}