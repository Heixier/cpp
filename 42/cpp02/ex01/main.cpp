#include "Fixed.hpp"

int	main(void)
{
	Fixed	a( 2.25f );
	Fixed	b( 100.3f );
	Fixed	c( -3 );

	// c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}