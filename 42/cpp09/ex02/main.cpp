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
	for (int i = 0; i < argc; i++)
	{
		// int num = ((std::pow(2, i) - std::pow(-1, i)) / 3);
		// std::cout << "Jacobsthal " << i<< ": " << generate_jacobsthal(i) << '\n';
	}

	// std::cout << "Argc: " << argc << '\n';
}