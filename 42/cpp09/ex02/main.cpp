#include <iostream>
#include <cmath>
#include <stdexcept>
#include "PmergeMe.hpp"
#include "colors.hpp"


int main (int argc, char **argv)
{
	try
	{
		PmergeMe(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << '\n';
	}
}