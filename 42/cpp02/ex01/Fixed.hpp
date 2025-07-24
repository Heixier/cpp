#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		void	setRawBits(const float raw);

		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& original);
		Fixed& operator= (const Fixed& fixed);
		~Fixed(void);

	private:
		int					value;
		static const int	bits = 8;
};

#endif
