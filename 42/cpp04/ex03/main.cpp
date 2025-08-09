#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource* lib = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* dummy = new Character();

	lib -> learnMateria(new Ice());
	lib -> learnMateria(new Ice());
	lib -> learnMateria(new Ice());
	lib -> learnMateria(new Ice());
	lib -> learnMateria(new Ice());

	lib -> learnMateria(NULL);

	me -> equip(lib -> createMateria("ice"));
	me -> equip(lib -> createMateria("cure"));
	me -> equip(lib -> createMateria("ice"));
	me -> equip(lib -> createMateria("ice"));
	me -> equip(lib -> createMateria("ice"));
	me -> equip(lib -> createMateria("ice"));


	me->use(0, *dummy);
	me->use(1, *dummy);
	me->use(2, *dummy);
	me->use(3, *dummy);
	me->use(4, *dummy);

	#ifdef DEBUG
	std::cout << "DEBUG TRIGGERED\n";

	AMateria* ice1 = new Ice("ice");
	AMateria* ice2 = new Ice(*static_cast<Ice *>(ice1));
	// ice2 = ice1; //crash

	me -> equip(ice1);
	me -> equip(ice2);
	me -> equip(NULL);

	me->use(0, *dummy);
	me->use(1, *dummy);
	me->use(2, *dummy);
	me->use(3, *dummy);
	me->use(4, *dummy);

	std::cout << "DEBUG END\n";
	#endif
	delete lib;
	delete me;
	delete dummy;
}