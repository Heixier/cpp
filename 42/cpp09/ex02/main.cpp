#include <iostream>
#include <cmath>
#include <stdexcept>
#include "PmergeMe.hpp"
#include "colors.hpp"

static int generate_jacobsthal(int n)
{
	if (n >= 33)
		throw std::runtime_error("Too many numbers!");
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

int main (int argc, char **argv)
{
	try
	{
		PmergeMe(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error" << '\n';
	}
	for (int i = 0; i < argc; i++)
	{
		// int num = ((std::pow(2, i) - std::pow(-1, i)) / 3);
		std::cout << "Jacobsthal " << i<< ": " << generate_jacobsthal(i) << '\n';
	}

	std::cout << "Argc: " << argc << '\n';
}

// Things to do:

// easy things

// Split the array into two 

// Create the jacobstal number sequence