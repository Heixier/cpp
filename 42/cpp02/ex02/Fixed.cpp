#include "Fixed.hpp"

int		Fixed::getRawBits(void) const
{
	return value;
}

static size_t power_of(int base, int power)
{
	size_t	output = base;

	for (int i = 0; i < power - 1; i++)
		output *= base;
	return (output);
}

void	Fixed::setRawBits(int const raw) { value = raw * power_of(2, bits); }

void	Fixed::setRawBits(const float raw) { value = roundf(raw * power_of(2, bits)); }

float	Fixed::toFloat(void) const { return (static_cast<float>(value) / static_cast<float>(power_of(2, bits))); }

int		Fixed::toInt(void) const { return (value / power_of(2, bits)); }

Fixed::Fixed(void) : value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(value);
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called" << std::endl;
	value = original.getRawBits();
}

Fixed&	Fixed::operator= (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = fixed.getRawBits();
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed)
{
	return (os << fixed.toFloat());
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }
