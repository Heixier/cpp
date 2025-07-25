#include "Fixed.hpp"
#include <sstream>
#include <string>

static void compare(const Fixed& left, const Fixed& right)
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

static void operations(const Fixed& left, const Fixed& right)
{
    std::cout << left << " + " << right << " = " << (left + right) << std::endl;
    std::cout << left << " - " << right << " = " << (left - right) << std::endl;
    std::cout << left << " * " << right << " = " << (left * right) << std::endl;
    std::cout << left << " / " << right << " = " << (left / right) << std::endl;

	Fixed dummy(left);
    std::cout << left << " += " << right << " = " << (dummy += right) << std::endl;
	dummy = left;
    std::cout << left << " -= " << right << " = " << (dummy -= right) << std::endl;
	dummy = left;
    std::cout << left << " *= " << right << " = " << (dummy *= right) << std::endl;
	dummy = left;
    std::cout << left << " /= " << right << " = " << (dummy /= right) << std::endl;
}

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

static void	minmax(const Fixed& left, const Fixed& right)
{
	std::cout << "Max of const " << left << " and const " << right << " is " << Fixed::max(left, right) << std::endl;;
	std::cout << "Min of const " << left << " and const " << right << " is " << Fixed::min(left, right) << std::endl;;
	
	Fixed a(left);
	Fixed b(right);

	std::cout << "Min of " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;;
	std::cout << "Max of " << a << " and " << b << " is " << Fixed::max(a, b) << std::endl;;
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
	compare(a, b);
	operations(a, b);
	increment(a);
	minmax(a, b);

	return (0);
}

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }
