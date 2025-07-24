#include "Fixed.hpp"
#include <sstream>
#include <string>

static void compare(const Fixed& left, const Fixed&right)
{
	if (left > right)
		std::cout << left << " is more than " << right << std::endl;
	if (left < right)
		std::cout << left << " is less than " << right << std::endl;
	if (left >= right)
		std::cout << left << " is more than or equal to " << right << std::endl;
	if (left <= right)
		std::cout << left << " is less than or equal to " << right << std::endl;
	if (left == right)
		std::cout << left << " is equal to " << right << std::endl;
	if (left != right)
		std::cout << left << " is not equal to " << right << std::endl;
}

static	void set_numbers(Fixed& a, Fixed& b)
{
	std::string input_str;
	std::istringstream	iss;
	float		left;
	float		right;

	std::cout << "Enter first number: ";
	std::getline(std::cin, input_str);
	iss.str(input_str);
	iss >> left;
	if (iss.fail() || input_str.length() <= 0)
	{
		std::cout << "Invalid number\n";
		return ;
	}
	std::cout << "Enter second number: ";
	std::getline(std::cin, input_str);
	iss.clear(), iss.str(input_str);
	iss >> right;
	if (iss.fail() || input_str.length() <= 0)
	{
		std::cout << "Invalid number\n";
		return ;
	}
	a = Fixed(left);
	b = Fixed(right);
}

int	main(void)
{
	Fixed	a, b;

	set_numbers(a, b);
	compare(a, b);

	return (0);
}