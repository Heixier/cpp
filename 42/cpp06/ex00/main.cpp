#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Invalid args\n", 1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
