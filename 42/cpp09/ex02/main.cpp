#include <iostream>
#include <cmath>
#include <stdexcept>

int generate_jacobsthal(int n)
{
	if (n >= 33)
		throw std::runtime_error("Too many numbers!");
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

int main (int argc, char **argv)
{
	(void)argv;
	for (int i = 0; i < 100; i++)
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