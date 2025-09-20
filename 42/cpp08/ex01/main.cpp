#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "Span.hpp"
#include "colors.hpp"

static bool	ft_aredigits(const std::string& input) { return (input.find_first_not_of("0123456789") == std::string::npos ? true : false); }
static void ft_newline(int size) { for (int i = 0; i < size; i++) { std::cout << '\n'; }; }

static std::vector<int> generate_random_vector(int size)
{
	std::vector<int> vect(size);
	srand(time(NULL));

	for (int i = 0; i < size; i++)
			vect[i] = rand() % __INT32_MAX__;
	return (vect);
}

static int get_number_input(const std::string& prompt)
{
	int value;
	std::string arg;
	std::istringstream iss;

	std::cout << prompt;
	std::getline(std::cin, arg);
	if (std::cin.eof())
	{
		throw std::invalid_argument("EOF is not a number (facepalm)...");
	}
	iss.str(arg);
	iss >> value;
	if (iss.fail() || arg.length() <= 0 || !ft_aredigits(arg))
		throw std::invalid_argument("Invalid number!");
	return (value);
}

static void test_small()
{
	std::cout << LIGHT_GREEN << "TEST: Small Spans >> \n" << END;

	std::cout << ICE_BLUE << "Created pdf array of size 5!\n" << END;
	Span pdf(5);
	pdf.addNumber(6);
	pdf.addNumber(3);
	pdf.addNumber(17);
	pdf.addNumber(9);
	pdf.addNumber(11);

	std::cout << "Checking pdf array: \n";
	pdf.print_array();

	std::cout << "Shortest span: " << pdf.shortestSpan() << "\n";
	std::cout << "Longest span: " << pdf.longestSpan() << "\n";

	static const int intarr[] = {1, 3, 5, 7, 9};
	std::vector<int> intvect(intarr, intarr + sizeof(intarr) / sizeof(intarr[0]));
	Span small(5);

	small.fill(intvect.begin(), intvect.end());

	std::cout << ICE_BLUE << "Created small array of size 5!\n" << END;
	small.print_array();

	std::cout << "Shortest span: " << small.shortestSpan() << "\n";
	std::cout << "Longest span: " << small.longestSpan() << "\n";
	std::cout << "\nAdding 42 to small array...\n";
	try
	{
		small.addNumber(42);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << END << '\n';
	}


	Span triangle(3);
	std::cout << ICE_BLUE << "Created triangle array of size 3!\n" << END;
	std::cout << "Trying to fill triangle array using the previous vector of size 5!\n";
	try
	{
		triangle.fill(intvect.begin(), intvect.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << END << '\n';
	}
}

static void test_duplicate()
{
	std::cout << LIGHT_GREEN << "TEST: Duplicated Spans >> \n" << END;

	Span duplicate(5);
	std::cout << ICE_BLUE << "Created duplicated array of size 5!\n" << END;

	std::cout << "Adding 5 to duplicate array...\n";
	duplicate.addNumber(5);

	std::cout << "Adding 5 to duplicate array...\n";
	duplicate.addNumber(5);

	std::cout << "Shortest span: " << duplicate.shortestSpan() << "\n";
	std::cout << "Longest span: " << duplicate.longestSpan() << "\n";

	std::cout << "\nAdding 42 to duplicate array...\n";
	duplicate.addNumber(42);

	std::cout << "Shortest span: " << duplicate.shortestSpan() << "\n";
	std::cout << "Longest span: " << duplicate.longestSpan() << "\n";
}

static void test_insufficient()
{
	std::cout << LIGHT_GREEN << "TEST: Insufficient Spans >> \n" << END;

	Span insufficient(123);
	std::cout << ICE_BLUE << "Created insufficient vector!\n" << END;
	try
	{
		std::cout << "empty.longestSpan(): " << insufficient.longestSpan() << '\n';
		std::cout << "empty.shortestSpan(): " << insufficient.shortestSpan() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << END << '\n';
	}
	try
	{
		std::cout << "empty.shortestSpan(): " << insufficient.shortestSpan() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << END << '\n';
	}

	std::cout << ICE_BLUE << "Adding one number to insufficient vector...\n" << END;
	insufficient.addNumber(42);

	try
	{
		std::cout << "empty.longestSpan(): " << insufficient.longestSpan() << '\n';
		std::cout << "empty.shortestSpan(): " << insufficient.shortestSpan() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << END << '\n';
	}

	try
	{
		std::cout << "empty.shortestSpan(): " << insufficient.shortestSpan() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << END << '\n';
	}
}

static void test_big()
{
	try
	{
		std::cout << LIGHT_GREEN << "TEST: Big Span >>" << END << '\n';
		int size = get_number_input("Enter size of big vector: " );
		if (size > 100000)
		{
			std::cerr << RED << size << " is too large!\n" << END;
			return;
		}
	
		Span big(size);
		std::cout << ICE_BLUE << "Created big vector of size: " << size << "!\n" << END;

		std::cout << YELLOW << "Space left: " << big.space_left() << END << '\n';
		std::vector<int> randvect = generate_random_vector(get_number_input("Enter size of random vector to append: "));
		big.fill(randvect.begin(), randvect.end());
		big.print_array();
		std::cout << "Shortest span: " << big.shortestSpan() << "\n";
		std::cout << "Longest span: " << big.longestSpan() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << END << '\n';
	}


}

int main()
{
	test_small();
	ft_newline(5);
	test_duplicate();
	ft_newline(5);
	test_insufficient();
	ft_newline(5);
	test_big();
}
