#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int main(void)
{
	ICharacter* me = new Character("me");
	ICharacter* him = new Character("Bob");
	AMateria* ice1 = new Ice("ice");
	AMateria* ice2 = new Ice("ice");

	me->equip(ice1);
	me->equip(ice1);
	me->use(1, *him);
	delete ice1;
	delete ice2;
	delete me;
	delete him;
}