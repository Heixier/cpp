#include <iostream>
#include <cmath>
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

	test jacobsthal limit
	test elements all exist and sorted (sorted is tested)
	fix output to only show before and after once
}