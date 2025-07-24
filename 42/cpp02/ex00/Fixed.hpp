#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed(void);
		Fixed(const Fixed& original);
		Fixed& operator= (const Fixed& fixed);
		~Fixed(void);

	private:
		int					value;
		static const int	bits = 8;
};

#endif
