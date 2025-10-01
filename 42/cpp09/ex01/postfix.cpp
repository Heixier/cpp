#include <iostream>

#include "ShuntingYard.hpp"
#include "colors.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << RED << "Invalid argument count!\n" << END,  1);
	try
	{
		ShuntingYard generator(argv[1]);
		generator.generate();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
}
