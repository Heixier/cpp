#include "Fixed.hpp"

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

static size_t power_of(int base, int power)
{
	size_t	output = base;

	for (int i = 0; i < power - 1; i++)
		output *= base;
	return (output);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

Fixed::Fixed(void) : value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called" << std::endl;
	value = original.getRawBits();
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }
