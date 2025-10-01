#include <iostream>
#include <cstdlib>
#include <cstring>
#include "RPN.hpp"
#include "colors.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error\n";
		return (1);
	}
	try
	{
		RPN rpn(argv[1]);
		rpn.calculate();
		rpn.evaluate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}