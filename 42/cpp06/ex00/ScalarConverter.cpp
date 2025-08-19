#include "ScalarConverter.hpp"
#include <limits>
#include <sstream>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <iomanip>

// Uses references to strings make sure this is static
typedef struct s_pseudo
{
	const std::string& p_float;
	const std::string& p_double;
}	t_pseudo;

static bool empty_str(const std::string& input)
{
	if (input.empty())
	{
		std::cout << "char: \n";
		std::cout << "int: 0\n";
		std::cout << "float: 0f\n";
		std::cout << "double: 0\n";
		return (true);
	}
	return (false);
}

static void print_pseudo(const t_pseudo& pseudos)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << pseudos.p_float << '\n';
	std::cout << "double: " << pseudos.p_double << '\n';
}

static bool pseudo(const std::string &input)
{
	static const t_pseudo pseudos[3] = {
	{"-inff" , "-inf"},
	{"+inff", "+inf"},
	{"nanf", "nan"} };

	for (size_t i = 0; i < (sizeof(pseudos)/sizeof(*pseudos)); i++)
	{
		if (input == pseudos[i].p_float || input == pseudos[i].p_double)
			return (print_pseudo(pseudos[i]), true);
	}
	return (false);
}

static bool try_char(const std::string &input)
{
	if (input.length() != 1)
		return (false);
	char c = input[0];
	
	std::cout << "char: " << (std::isprint(c) ? input : "Non displayable") << "\n";

	if (c >= '0' && c <= '9')
		c -= '0';

	std::cout << "int: " << static_cast<int>(c) << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << '\n';
	return (true);
}

static bool try_int(const std::string &input)
{
	std::istringstream iss;
	int target;

	iss.str(input);
	iss >> target;
	if (iss.fail() || iss.peek() != EOF)
		return (false);
	
	if (std::isprint(target))
		std::cout << "char: " << static_cast<char>(target) << '\n';
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << target << '\n';

	// int will never overflow a float
	std::cout << "float: " << static_cast<float>(target) << "f\n";
	std::cout << "double: " << static_cast<double>(target) << '\n';
	return (true);
}

void ScalarConverter::convert(const std::string& input)
{
	if (empty_str(input) || pseudo(input))
		return;

	if (try_char(input))
		return;
	if (try_int(input))
		return;

	static const std::string types[4] = { "char", "int", "float", "double" };
	for (int i = 0; i < 4; i++)
		std::cout << types[i] << ": impossible\n";
}

ScalarConverter::ScalarConverter() { }
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& other) { return ((void)other, *this); }
ScalarConverter::~ScalarConverter() { }