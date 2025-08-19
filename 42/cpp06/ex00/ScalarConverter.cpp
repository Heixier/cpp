#include "ScalarConverter.hpp"
#include <limits>
#include <sstream>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <iomanip>

typedef struct s_pseudo
{
	const std::string& p_float;
	const std::string& p_double;
}	t_pseudo;

static void print_pseudo(const t_pseudo& pseudos)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << pseudos.p_float << '\n';
	std::cout << "double: " << pseudos.p_double << '\n';
}

static bool pseudo(const std::string &input)
{
	static const t_pseudo pseudos[3] = { "-inff" , "-inf" , "+inff", "+inf", "nanf", "nan" };

	for (size_t i = 0; i < (sizeof(pseudos)/sizeof(*pseudos)); i++)
	{
		if (pseudos[i].p_float == input || pseudos[i].p_double == input)
			return (print_pseudo(pseudos[i]), true);
	}
	return (false);
}

void ScalarConverter::convert(const std::string& input)
{
	// Check if special case

	if (pseudo(input))
		return;
	// If not special case
	// Check which type it is


}

ScalarConverter::ScalarConverter() { }
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& other) { return ((void)other, *this); }
ScalarConverter::~ScalarConverter() { }