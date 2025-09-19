#include <iostream>

#include "Span.hpp"

int main()
{
	// Span test(5);
	// test.addNumber(3);
	// test.print_array();
	// std::cout << "Longest span: " << test.longestSpan() << '\n';
	// std::cout << "Shortest span: " << test.shortestSpan() << '\n';

	// test.addNumber(7);
	// test.addNumber(1);
	// test.addNumber(2);
	// test.addNumber(2);
	// test.addNumber(222);
	// test.print_array();
	// std::cout << "Longest span: " << test.longestSpan() << '\n';
	// std::cout << "Shortest span: " << test.shortestSpan() << '\n';
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print_array();
	std::cout << "lengths: \n";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.print_array();
}
