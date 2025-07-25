#include "Fixed.hpp"
#include <sstream>
#include <string>

// static void compare(const Fixed& left, const Fixed& right)
// {
// 	if (left > right)
// 		std::cout << left << " is more than " << right << std::endl;
// 	if (left < right)
// 		std::cout << left << " is less than " << right << std::endl;
// 	if (left >= right)
// 		std::cout << left << " is more than or equal to " << right << std::endl;
// 	if (left <= right)
// 		std::cout << left << " is less than or equal to " << right << std::endl;
// 	if (left == right)
// 		std::cout << left << " is equal to " << right << std::endl;
// 	if (left != right)
// 		std::cout << left << " is not equal to " << right << std::endl;
// }

// static void operations(const Fixed& left, const Fixed& right)
// {
//     std::cout << left << " + " << right << " = " << (left + right) << std::endl;
//     std::cout << left << " - " << right << " = " << (left - right) << std::endl;
//     std::cout << left << " * " << right << " = " << (left * right) << std::endl;
//     std::cout << left << " / " << right << " = " << (left / right) << std::endl;

// 	Fixed dummy(left);
//     std::cout << left << " += " << right << " = " << (dummy += right) << std::endl;
// 	dummy = left;
//     std::cout << left << " -= " << right << " = " << (dummy -= right) << std::endl;
// 	dummy = left;
//     std::cout << left << " *= " << right << " = " << (dummy *= right) << std::endl;
// 	dummy = left;
//     std::cout << left << " /= " << right << " = " << (dummy /= right) << std::endl;
// }

static void	increment(const Fixed& left)
{
	Fixed	dummy(left);
	std::cout << "Post increment\nFirst call: " << dummy << "++ = " << dummy++ << std::endl;
	std::cout << "Second call: " << dummy << std::endl;
	dummy = left;
	std::cout << "Pre increment\n++" << dummy << " = " << ++dummy << std::endl;
	dummy = left;
	std::cout << "Post increment\nFirst call: " << dummy << "-- = " << dummy-- << std::endl;
	std::cout << "Second call: " << dummy << std::endl;
	dummy = left;
	std::cout << "Pre increment\n--" << dummy << " = " << --dummy << std::endl;
}

static	bool set_numbers(Fixed& a, Fixed& b)
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
		return (std::cout << "Invalid number\n", false);
	std::cout << "Enter second number: ";
	std::getline(std::cin, input_str);
	iss.clear(), iss.str(input_str);
	iss >> right;
	if (iss.fail() || input_str.length() <= 0)
		return (std::cout << "Invalid number\n", false);
	a = Fixed(left);
	b = Fixed(right);
	return (true);
}

int	main(void)
{
	Fixed	a, b;

	if (!set_numbers(a, b))
		return (1);
	// compare(a, b);
	// operations(a, b);
	increment(a);

	return (0);
}