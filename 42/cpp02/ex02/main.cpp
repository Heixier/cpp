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

#include <cstdio>
static void operations(const Fixed& left, const Fixed& right)
{
    printf("left raw bits: %d\nright raw bits: %d\n", left.getRawBits(), right.getRawBits());
    
    Fixed sum = left + right;
    printf("sum raw bits: %d\n", sum.getRawBits());
    printf("sum toFloat(): %f\n", sum.toFloat());
    
    std::cout << "sum via << operator: " << sum << std::endl;
    std::cout << left << " + " << right << " = " << sum << std::endl;
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
	operations(a, b);

	return (0);
}