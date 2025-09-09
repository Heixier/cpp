#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

void print_vect(const std::vector<int>& vect)
{
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << '\n';
}

int main()
{
	static const int arr[] = {1, 3, 5, 7, 9};
	std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(arr[0]));
	print_vect(vect);

	try
	{
		std::cout << easyfind(vect, 6);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught!\n";
	}
}