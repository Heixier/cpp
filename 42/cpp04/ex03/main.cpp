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
	IMateriaSource* src_dfl = new MateriaSource();
	ICharacter* chr_dfl = new Character();
	Ice* ice_dfl = new Ice();
	Cure* cure_dfl = new Cure();

	std::cout << LIGHT_GREEN << "\n< Preparing for deep copy test (ignore output until next section)) >\n" << END;
	src_dfl -> learnMateria(ice_dfl);
	src_dfl -> learnMateria(NULL); // just in case

	chr_dfl -> equip(src_dfl -> createMateria("ice"));
	chr_dfl -> equip(src_dfl -> createMateria("ice"));
	chr_dfl -> equip(NULL); // just in case

	std::cout << LIGHT_GREEN << "\n< Copy constructor test > \n" << END;
	IMateriaSource* src_copy = new MateriaSource(*static_cast<const MateriaSource *>(src_dfl));
	ICharacter* chr_copy = new Character(*static_cast<const Character *>(chr_dfl));

	std::cout << LIGHT_GREEN << "\n<< Only ice should be recognised >> \n" << END;
	AMateria* tmp;
	tmp = src_copy -> createMateria("ice"); // should be recognised
	delete tmp;
	tmp = src_copy -> createMateria("cure"); // should not be recognised
	delete tmp;

	std::cout << LIGHT_GREEN << "\n<< Each use attempt should match 1:1 >> \n" << END;
	for (int i = 0; i < 5; i++)
	{
		chr_dfl -> use(i, *chr_copy);
		chr_copy -> use(i, *chr_dfl);
	}

	std::cout << LIGHT_GREEN << "\n< Copy assignment operator tests > \n" << END;
	std::cout << LIGHT_GREEN << "\n<< Make src_copy learn cure\n" << END;
	src_copy -> learnMateria(cure_dfl);
	std::cout << LIGHT_GREEN << "\n"<< "Assign src_copy to src_dfl\n" << END;
	*static_cast<MateriaSource *>(src_dfl) = *static_cast<MateriaSource *>(src_copy);

	std::cout << LIGHT_GREEN << "\n"<< "Add cure to chr_copy using src_dfl\n" << END;
	chr_copy -> equip(src_dfl -> createMateria("cure"));
	std::cout << LIGHT_GREEN << "\n"<< "Assign chr_copy to chr_dfl\n" << END;
	*static_cast<Character *>(chr_dfl) = *static_cast<Character *>(chr_copy);
	std::cout << LIGHT_GREEN << "\n"<< "Test all skills again\n" << END;

	std::cout << LIGHT_GREEN << "\n<< Each use attempt should match 1:1 >> \n" << END;
	for (int i = 0; i < 5; i++)
	{
		chr_dfl -> use(i, *chr_copy);
		chr_copy -> use(i, *chr_dfl);
	}

	std::cout << ORANGE << "\n< Destructor tests >\n" << END;
	delete chr_copy;
	delete src_copy;
	delete chr_dfl;
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