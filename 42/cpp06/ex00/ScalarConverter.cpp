#include "ScalarConverter.hpp"
#include <cfloat>
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
} t_pseudo;

typedef enum e_types
{
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
} e_types;

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

static void print_error(const std::string &dummy)
{
	(void)dummy;
	static const std::string types[4] = { "char", "int", "float", "double" };
	for (int i = 0; i < 4; i++)
		std::cout << types[i] << ": impossible\n";
}

static int get_type(const std::string& input)
{
	if (input.length() == 1 && !(input[0] >= '0' && input[0] <= '9')) // Digits will be treated as ints. PDF did not specify.
		return (CHAR);

	std::istringstream iss;
	iss.str(input);

	size_t float_dot_pos = input.find_first_of('.');
	if (float_dot_pos + 1 == input.size()) // dot '.' with nothing behind will be considered invalid. PDF did not specify.
		return (ERROR);

	if (float_dot_pos == std::string::npos)
	{
		int target;
		iss >> target;
		if (iss.fail() || iss.peek() != EOF)
			return (ERROR);
		return (INT);
	}

	long double target;

	if (input[input.size() -1] == 'f')
	{
		// Remove the f
		std::string float_str(input);
		float_str.erase(float_str.size() - 1);

		iss.str(float_str);
		iss >> target;
		if (iss.fail() || iss.peek() != EOF)
			return (ERROR);
		return (FLOAT);
	}

	iss >> target;
	if (iss.fail() || iss.peek() != EOF)
		return (ERROR);
	return (DOUBLE);
}

static void print_char(const std::string &input)
{
	std::cout << "char: " << (std::isprint(input[0]) ? input : "Non displayable") << "\n";

	std::cout << "int: " << static_cast<int>(input[0]) << '\n';

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(input[0]) << "f\n";
	std::cout << "double: " << static_cast<double>(input[0]) << '\n';
}

static void print_int(const std::string &input)
{
	std::istringstream iss;
	int target;

	iss.str(input);
	iss >> target;
	if (std::isprint(static_cast<char>(target)) && target >= -127 && target <= 128)
		std::cout << "char: " << static_cast<char>(target) << '\n';
	else
		std::cout << "char: Non displayable\n";

	std::cout << "int: " << target << '\n';

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(target) << "f\n";
	std::cout << "double: " << static_cast<double>(target) << '\n';
}

static void print_float(const std::string &input)
{
	std::istringstream iss;
	float target;

	// Remove the f
	std::string float_str(input);
	float_str.erase(float_str.size() - 1);

	iss.str(float_str);
	iss >> target;
	// if (iss.fail() || iss.peek() != EOF)
	// {
	// 	print_error(input);
	// 	return;
	// }

	// Just let it do whatever it wants, loss of precision handling not specified in PDF

	std::cout << "print float: " << target << '\n';

	if (std::isprint(static_cast<char>(target)) && target >= -127 && target <= 128)
		std::cout << "char: " << static_cast<char>(target) << '\n';
	else
		std::cout << "char: Non displayable\n";

	if (static_cast<long long>(target) > std::numeric_limits<int>::max() || static_cast<long long>(target) < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(target) << '\n';

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << target << "f\n";
	std::cout << "double: " << static_cast<double>(target) << '\n';
}

static void print_double(const std::string &input)
{
	std::istringstream iss;
	double target;

	iss.str(input);
	iss >> target;
	// if (iss.fail() || iss.peek() != EOF)
	// {
	// 	print_error(input);
	// 	return;
	// }

	if (std::isprint(static_cast<char>(target)) && target >= -127 && target <= 128)
		std::cout << "char: " << static_cast<char>(target) << '\n';
	else
		std::cout << "char: Non displayable\n";

	if (static_cast<long long>(target) > std::numeric_limits<int>::max() || static_cast<long long>(target) < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(target) << '\n';

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(target) << "f\n";
	std::cout << "double: " << target << '\n';
}

void ScalarConverter::convert(const std::string& input)
{
	static void (*print_type[5])(const std::string& input) = {
		&print_char,
		&print_int,
		&print_float,
		&print_double,
		&print_error
	};

	if (empty_str(input) || pseudo(input))
		return;

	print_type[get_type(input)](input);
}

ScalarConverter::ScalarConverter() { }
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& other) { return ((void)other, *this); }
ScalarConverter::~ScalarConverter() { }