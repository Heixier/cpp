#include <iostream>
#include <exception>
#include <algorithm>

template<typename T>
int easyfind(const T& int_container, const int target)
{
	if (std::find(int_container.begin(), int_container.end(), target) == int_container.end)
		throw std::exception();
	return (target);
}
