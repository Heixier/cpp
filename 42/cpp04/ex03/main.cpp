#include <iostream>
#include <sstream>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "colors.hpp"

#define SEP "//////////////////////////////////////////////////"

#ifdef EVAL
void eval(void)
{
	// Anything in this section should not compile because they're abstract, uncomment any of them to test
	// IMateriaSource* tmp = new IMateriaSource;
	// ICharacter* ctmp = new ICharacter();
	// AMateria* tmpm = new AMateria();
	// AMateria* tmpm = new AMateria("ice");

	std::cout << LIGHT_GREEN << "|| Default constructor tests ||\n" << END;
	IMateriaSource* src_dfl = new MateriaSource();
	ICharacter* chr_dfl = new Character();
	Ice* ice_dfl = new Ice();
	Cure* cure_dfl = new Cure();

	std::cout << LIGHT_GREEN << "\n|| Preparing for deep copy test ||\n" << END;
	src_dfl -> learnMateria(ice_dfl);
	src_dfl -> learnMateria(NULL); // just in case

	chr_dfl -> equip(src_dfl -> createMateria("ice"));
	chr_dfl -> equip(src_dfl -> createMateria("ice"));
	chr_dfl -> equip(NULL); // just in case

	std::cout << LIGHT_GREEN << "\n|| Copy constructor test ||\n" << END;
	IMateriaSource* src_copy = new MateriaSource(*static_cast<const MateriaSource *>(src_dfl));
	ICharacter* chr_copy = new Character(*static_cast<const Character *>(chr_dfl));

	std::cout << FF4 << "\n<< Only ice should be recognised >> \n" << END;
	AMateria* tmp;
	tmp = src_copy -> createMateria("ice"); // should be recognised
	delete tmp;
	tmp = src_copy -> createMateria("cure"); // should not be recognised
	delete tmp;

	std::cout << FF4 << "\n<< Each use attempt should match 1:1 >> \n" << END;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ": [chr_dfl ] ";
		chr_dfl -> use(i, *chr_copy);
		std::cout << i << ": [chr_copy] ";
		chr_copy -> use(i, *chr_dfl);
	}

	std::cout << LIGHT_GREEN << "\n|| Copy assignment operator tests ||\n" << END;
	std::cout << FF4 << "\n<< Make src_copy learn cure >>\n" << END;
	src_copy -> learnMateria(cure_dfl);
	std::cout << FF4 << "\n<< Assign src_copy to src_dfl\n" << END;
	*static_cast<MateriaSource *>(src_dfl) = *static_cast<MateriaSource *>(src_copy);

	std::cout << ORANGE << "\n<< Add cure to chr_copy using src_dfl\n" << END;
	chr_copy -> equip(src_dfl -> createMateria("cure"));

	std::cout << ORANGE << "\n<< Unequip slot 0 from chr_copy >>\n" << END;
	chr_copy -> unequip(0);

	std::cout << FF4 << "\n<< Should reflect the" << ORANGE << " changes " << FF4 << "that were made >> \n" << END;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ": [chr_dfl ] ";
		chr_dfl -> use(i, *chr_copy);
		std::cout << i << ": [chr_copy] ";
		chr_copy -> use(i, *chr_dfl);
	}

	std::cout << FF4 << "\n<< Assign chr_copy to chr_dfl >>\n" << END;
	*static_cast<Character *>(chr_dfl) = *static_cast<Character *>(chr_copy);
	std::cout << FF4 << "\n<< Test all skills again >>\n" << END;

	std::cout << FF4 << "\n<< Each use attempt should match 1:1 >>\n" << END;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ": [chr_dfl ] ";
		chr_dfl -> use(i, *chr_copy);
		std::cout << i << ": [chr_copy] ";
		chr_copy -> use(i, *chr_dfl);
	}

	std::cout << ORANGE << "\n|| Destructor tests ||\n" << END;
	delete chr_copy;
	delete src_copy;
	delete chr_dfl;
	delete src_dfl;
}

#endif

static bool get_name(const std::string& type, std::string &input)
{
        std::cout << FF4 << type << " name: " << FF1;
        std::getline(std::cin, input);
        std::cout << END;
        if (std::cin.eof())
			return (std::cout << RED << "\noi\n" << END, false);
		if (input.empty())
			input = "Cloud";
        return (true);
}

static int get_int_from_char(const std::string& allowed)
{
	std::string input;
	
	std::cout << GREY << "Enter a character: " << FF3;
	std::getline(std::cin, input);
	std::cout << END;
	if (std::cin.eof())
		return (-1);
	if (input.length() != 1 || input.find_first_of(allowed) == std::string::npos)
	{
		std::cout << RED << "Invalid character!\n" << END;
		return (-1);
	}
	return (input[0]);
}

static bool learn(IMateriaSource* src)
{
	const static std::string keys = "ic";
	AMateria* to_learn = NULL;

	std::cout << FF4 << "\nWhat would you like to produce?\n"
	<< ICE_BLUE << "(i)ce\n" 
	<< GREEN << "(c)ure\n"
	<< FF4 "\n" << END;

	int choice = get_int_from_char(keys);
	if (choice < 0)
		return (false);
	switch (choice)
	{
		case 'i':
		{
			to_learn = new Ice();
			break;
		}
		case 'c':
		{
			to_learn = new Cure();
			break;
		}
		default:
			break;
	}
	src -> learnMateria(to_learn);
	return (true);
}

static bool equip(IMateriaSource* src, ICharacter* player)
{
	const static std::string keys = "ic";

	std::cout << FF4 << "\nWhat would you like to equip?\n"
	<< ICE_BLUE << "(i)ce\n" 
	<< GREEN << "(c)ure\n"
	<< FF4 "\n" << END;
	int choice = get_int_from_char(keys);
	if (choice < 0)
		return (false);
	switch (choice)
	{
		case 'i':
		{
			player -> equip(src -> createMateria("ice"));
			break;
		}
		case 'c':
		{
			player -> equip(src -> createMateria("cure"));
			break;
		}
		default:
		{
			player -> equip(src -> createMateria("???"));
			break;
		}
	}
	return (true);
}

static bool use(ICharacter *player, ICharacter *target)
{
	const static std::string keys = "qwer";

	std::cout << FF4 << "\nWhat would you like to use? [ q, w, e, r ]\n\n" << END;
	int choice = get_int_from_char(keys);
	if (choice < 0)
		return (false);
	int option = keys.find(choice);
	player -> use(option, *target);
	return (true);
}

static bool unequip(ICharacter *player)
{
	const static std::string keys = "qwer";

	std::cout << FF4 << "What would you like to unequip? [ q, w, e, r ]\n\n" << END;
	int choice = get_int_from_char(keys);
	if (choice < 0)
		return (false);
	int option = keys.find(choice);
	player -> unequip(option);
	return (true);
}

int main(void)
{
	std::string player1_name;
	std::string player2_name;

	#ifdef EVAL
	eval();
	return (0);
	#endif

	if (!get_name("Player 1", player1_name) || !get_name("Player 2", player2_name))
		return (0);
	IMateriaSource* src1 = new MateriaSource();
	IMateriaSource* src2 = new MateriaSource();
	ICharacter* p1 = new Character(player1_name);
	ICharacter* p2 = new Character(player2_name);

	std::string input;
	bool running = true;
	int	turn = 0;
	int option = 0;
	const static std::string keys = "leudix";

	while (running)
	{
		if (std::cin.eof())
			break;
		std::cout << (turn == 0 ? FF1 : FF3 ) << '\n' << SEP << "\n" << (turn == 0 ? p1 -> getName() : p2 -> getName()) << "'s turn!\n\n" << END;
		std::cout << FF4 << "Options: (l)earn, (e)quip, (d)rop, (u)se, (i)nfo, e(x)it\n\n" << END;
		option = get_int_from_char(keys);
		if (option == -1)
			continue;
		switch (option)
		{
			case 'l':
			{
				learn(turn == 0 ? src1 : src2);
				break;
			}
			case 'e':
			{
				equip(turn == 0 ? src1 : src2, turn == 0 ? p1 : p2);
				break;
			}
			case 'u':
			{
				use(turn == 0 ? p1 : p2, turn == 0 ? p2 : p1);
				break;
			}
			case 'd':
			{
				unequip(turn == 0 ? p1 : p2);
				continue;
			}
			case 'i':
			{
				static_cast<Character *>(turn == 0 ? p1 : p2) -> check_inventory();
				static_cast<Character *>(turn == 0 ? p1 : p2) -> check_sell_inventory();
				static_cast<MateriaSource *>(turn == 0 ? src1 : src2) -> list_materia();
				continue;
			}
			case 'x':
			{
				std::cout << RED << "World destroyed.\n" << END;
				running = false;
				break;
			}
			default:
				std::cout << RED << "Invalid choice!\n" << END;
		}
		turn = (turn + 1) % 2;
	}

	delete p2;
	delete p1;
	delete src2;
	delete src1;
}