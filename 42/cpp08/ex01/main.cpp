#include <iostream>

#include "Span.hpp"

int main()
{
	Span test(5);
	test.addNumber(3);
	test.print_array();
	std::cout << "Longest span: " << test.longestSpan() << '\n';
	std::cout << "Shortest span: " << test.shortestSpan() << '\n';

	test.addNumber(7);
	test.addNumber(1);
	test.print_array();
	std::cout << "Longest span: " << test.longestSpan() << '\n';
	std::cout << "Shortest span: " << test.shortestSpan() << '\n';

}
