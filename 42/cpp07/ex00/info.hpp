#ifndef INFO_HPP
#define INFO_HPP

#include "whatever.hpp"

template <typename T>
void info(T& first, T& second)
{
	std::cout << "first: " << first << " second: " << second << '\n';

	std::cout << "\nLowest value: " << (&(min(first, second)) == &first ? "first" : "second") << '\n';
	std::cout << "Highest value: " << (&(max(first, second)) == &first ? "first" : "second") << '\n';

	std::cout << "\nSwapping first and second!\n";
	swap(first, second);
	std::cout << "\nfirst: " << first << " second: " << second << '\n';

	std::cout << "\nLowest value: " << (&(min(first, second)) == &first ? "first" : "second") << '\n';
	std::cout << "Highest value: " << (&(max(first, second)) == &first ? "first" : "second") << '\n';
}

#endif