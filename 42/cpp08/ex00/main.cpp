#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include "colors.hpp"
#include <unistd.h>

template<typename T>
void print_vect(const std::vector<T>& vect, const char* color)
{
	std::cout << color << "Vector contents: {";
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << (i + 1 == vect.size() ? "" : ", ");
	}
	std::cout << "}\n" << END;
}

template<typename T>
void search_vect(const std::vector<T>& vect)
{
	for (int i = *std::min_element(vect.begin(), vect.end()); i < (*std::max_element(vect.begin(), vect.end()) + 1); i++)
	{
		std::cout << "Looking for " << static_cast<T>(i) << ": \n";
		try
		{
			std::cout << LIGHT_GREEN << "Result: " << static_cast<T>(easyfind(vect, i)) << " found!\n" << END;
		}
		catch (const std::exception &e)
		{
			std::cout << RED << "Exception caught!\n" << END;
		}
		usleep(50000);
	}
}

int main()
{
	static const int intarr[] = {1, 3, 5, 7, 9};
	std::vector<int> intvect(intarr, intarr + sizeof(intarr) / sizeof(intarr[0]));
	print_vect(intvect, ICE_BLUE);
	search_vect(intvect);

	static const char chararr[] = {'a', 'c', 'd', 'f', 'x'};
	std::vector<char> charvect(chararr, chararr + sizeof(chararr) / sizeof(chararr[0]));
	print_vect(charvect, ICE_BLUE);
	search_vect(charvect);
}