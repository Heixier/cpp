#ifndef INFO_HPP
#define INFO_HPP

#include <iostream>

#include "whatever.hpp"

template <typename T>
void info(T& first, T& second)
{
	std::cout << "first: " << first << " second: " << second << '\n';

	std::cout << "\nLowest value: " << (&(min(first, second)) == &first ? "first" : "second") << '\n';
	std::cout << "Highest value: " << (&(max(first, second)) == &first ? "first" : "second") << '\n';


	std::cout << "\nSwapping values of first and second: \n";
	std::cout << "\nfirst addr: " << &first << "\nsecond addr: " << &second << '\n';

	swap(first, second);
	std::cout << "\nMake sure only values (not addresses) were swapped:\n";
	std::cout << "first addr: " << &first << "\nsecond addr: " << &second << '\n';
	std::cout << "\nfirst: " << first << " second: " << second << '\n';

	std::cout << "\nLowest value: " << (&(min(first, second)) == &first ? "first" : "second") << '\n';
	std::cout << "Highest value: " << (&(max(first, second)) == &first ? "first" : "second") << '\n';
}

#endif