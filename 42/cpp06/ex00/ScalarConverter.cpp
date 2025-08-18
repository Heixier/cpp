#include "ScalarConverter.hpp"
#include <limits>
#include <sstream>
#include <cctype>
#include <iostream>

static bool char_convert(const std::string& input)
{
	std::istringstream iss;
	char output;

	iss.str(input);
	iss >> output;
	if (iss.fail() || !iss.eof())

		return (false);
	
	if (std::isprint(output))
		std::cout << "char: " << output << '\n';
	else
		std::cout << "char: Non displayable\n";

	if (static_cast<long long>(output) > std::numeric_limits<int>::max() || static_cast<long long>(output) < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(output) << '\n';

	if (static_cast<long double>(output) > std::numeric_limits<float>::max() || static_cast<long double>(output) < std::numeric_limits<float>::min())
		std::cout << "float: nanf\n";
	else
		std::cout << "float: " << static_cast<float>(output) << '\n';
		
	if (static_cast<long double>(output) > std::numeric_limits<double>::max() || static_cast<long double>(output) < std::numeric_limits<double>::min())
		std::cout << "double: nan\n";
	else
		std::cout << "double: " << static_cast<double>(output) << '\n';
}

static bool int_convert(const std::string& input)
{
	std::istringstream iss;
	int output;

	iss.str(input);
	iss >> output;
	if (iss.fail())
		return (false);

	if (std::isprint(output))
		std::cout << "char: " << output << '\n';
	else
		std::cout << "char: Non displayable\n";

	if (static_cast<long long>(output) > std::numeric_limits<int>::max() || static_cast<long long>(output) < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(output) << '\n';

	if (static_cast<long double>(output) > std::numeric_limits<float>::max() || static_cast<long double>(output) < std::numeric_limits<float>::min())
		std::cout << "float: nanf\n";
	else
		std::cout << "float: " << static_cast<float>(output) << '\n';
		
	if (static_cast<long double>(output) > std::numeric_limits<double>::max() || static_cast<long double>(output) < std::numeric_limits<double>::min())
		std::cout << "double: nan\n";
	else
		std::cout << "double: " << static_cast<double>(output) << '\n';
}

static bool float_convert(const std::string &input)
{
	std::istringstream iss;
	float output;

	if (input.back() == 'f')
		;sdsdada
	iss.str(input);
	iss >> output;
	if (iss.fail())
		return (false);
	if (std::isprint(output))
		std::cout << "char: " << output << '\n';
	else
		std::cout << "char: Non displayable\n";

	if (static_cast<long long>(output) > std::numeric_limits<int>::max() || static_cast<long long>(output) < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(output) << '\n';

	if (static_cast<long double>(output) > std::numeric_limits<float>::max() || static_cast<long double>(output) < std::numeric_limits<float>::min())
		std::cout << "float: nanf\n";
	else
		std::cout << "float: " << static_cast<float>(output) << '\n';
		
	if (static_cast<long double>(output) > std::numeric_limits<double>::max() || static_cast<long double>(output) < std::numeric_limits<double>::min())
		std::cout << "double: nan\n";
	else
		std::cout << "double: " << static_cast<double>(output) << '\n';
}

static bool double_convert(const std::string &input)
{
	std::istringstream iss;
	double output;

	iss.str(input);
	iss >> output;
	if (iss.fail())
		std::cout << "double: nan\n";
	else
		std::cout << "double: " << output << '\n';
}

void ScalarConverter::convert(const std::string& input)
{
	if (char_convert(input))
		return;
	if (int_convert(input))
		return;
	if (float_convert(input))
		return;
	if (double_convert(input))
		return;
	
	std::cout << "Not anything\n";
}

ScalarConverter::ScalarConverter() { }
ScalarConverter::ScalarConverter(const ScalarConverter& other) { }
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& other) { return (*this); }
ScalarConverter::~ScalarConverter() { }