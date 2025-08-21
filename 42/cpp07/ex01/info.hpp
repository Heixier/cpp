#ifndef INFO_HPP
#define INFO_HPP

#include <iostream>

template <typename Ptr, typename Len>
void info(Ptr& array, Len length)
{
	for (int i = 0; i < length; i++)
	{
		if (i + 1 >= length)
			std::cout << array[i] << '\n';
		else
		 	std::cout << array[i] << ", ";
	}
}

#endif