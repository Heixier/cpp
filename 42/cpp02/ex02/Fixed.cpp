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

void	Fixed::setRawBits(int const raw) { value = raw; }

float	Fixed::toFloat(void) const { return (static_cast<float>(value) / static_cast<float>(power_of(2, bits))); }

int		Fixed::toInt(void) const { return (value / power_of(2, bits)); }

Fixed::Fixed(void) : value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	value = raw * power_of(2, bits);	
}

Fixed::Fixed(const float raw)
{

	std::cout << "Float constructor called" << std::endl;
	value = roundf(raw * power_of(2, bits));	
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

bool	Fixed::operator> (const Fixed& operand) const { return (this -> getRawBits() > operand.getRawBits()); }
bool	Fixed::operator< (const Fixed& operand) const { return (this -> getRawBits() < operand.getRawBits()); }
bool	Fixed::operator>= (const Fixed& operand) const { return (this -> getRawBits() >= operand.getRawBits()); }
bool	Fixed::operator<= (const Fixed& operand) const { return (this -> getRawBits() <= operand.getRawBits()); }
bool	Fixed::operator== (const Fixed& operand) const { return (this -> getRawBits() == operand.getRawBits()); }
bool	Fixed::operator!= (const Fixed& operand) const { return (this -> getRawBits() != operand.getRawBits()); }


Fixed	Fixed::operator+ (const Fixed& operand) const
{
	Fixed	result;
	return (result.setRawBits((value + operand.getRawBits())), result);
}

Fixed	Fixed::operator- (const Fixed& operand) const
{
	Fixed	result;
	return (result.setRawBits((value - operand.getRawBits())), result);
}

Fixed	Fixed::operator* (const Fixed& operand) const
{
	Fixed	result;
	return (result.setRawBits(static_cast<int>((value * operand.getRawBits()) / power_of(2, bits))), result);
}

Fixed	Fixed::operator/ (const Fixed& operand) const
{
	Fixed	result;
	return (result.setRawBits(static_cast<int>((value / operand.getRawBits()) * power_of(2, bits))), result);
}

// Optional
Fixed&	Fixed::operator+= (const Fixed& operand) { return (value += operand.getRawBits(), *this); }
Fixed&	Fixed::operator-= (const Fixed& operand) { return (value -= operand.getRawBits(), *this); }
Fixed&	Fixed::operator*= (const Fixed& operand) { return (value = static_cast<int>(((value * operand.getRawBits()) / power_of(2, bits))), *this); }
Fixed&	Fixed::operator/= (const Fixed& operand) { return (value = static_cast<int>(((value / operand.getRawBits()) * power_of(2, bits))), *this); }

// Pre
Fixed&	Fixed::operator++() { return (value++, *this); }

// Post
Fixed	Fixed::operator++(int)
{
	Fixed	before_increment(*this);
	++(*this);
	return (before_increment);
}

Fixed&	Fixed::operator--() { return (value--, *this); }

Fixed	Fixed::operator--(int)
{
	Fixed	before_increment(*this);
	--(*this);
	return (before_increment);
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed) { return (os << fixed.toFloat()); }

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }
