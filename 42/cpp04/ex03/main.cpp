#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "colors.hpp"

#ifdef EVAL
void eval(void)
{
	// Anything in this section should not compile because they're abstract, uncomment any of them to test
	// IMateriaSource* tmp = new IMateriaSource;
	// ICharacter* ctmp = new ICharacter();
	// AMateria* tmpm = new AMateria();
	// AMateria* tmpm = new AMateria("ice");

	std::cout << LIGHT_GREEN << "< Default constructor tests >\n" << END;
	std::cout << GREY << "IMateriaSource* src_dfl = new MateriaSource():\n";
	IMateriaSource* src_dfl = new MateriaSource();
	std::cout << GREY << "ICharacter* chr_dfl = new Character():\n";
	ICharacter* chr_dfl = new Character();
	std::cout << GREY << "Ice* ice_dfl = new Ice():\n";
	Ice* ice_dfl = new Ice();
	std::cout << GREY << "Cure* cure_dfl = new Cure():\n";
	Cure* cure_dfl = new Cure();

	std::cout << GREY << "delete cure_dfl:\n";
	delete cure_dfl;
	std::cout << GREY << "delete ice_dfl:\n";
	delete ice_dfl;
	std::cout << GREY << "delete chr_dfl:\n";
	delete chr_dfl;
	std::cout << GREY << "delete src_dfl:\n";
	delete src_dfl;

}

#endif

int main(void)
{
	#ifdef EVAL
	eval();
	return (0);
	#endif

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



	delete lib;
	delete me;
	delete dummy;
}