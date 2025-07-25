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
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator> (const Fixed& operand) const;
		bool	operator< (const Fixed& operand) const;
		bool	operator>= (const Fixed& operand) const;
		bool	operator<= (const Fixed& operand) const;
		bool	operator== (const Fixed& operand) const;
		bool	operator!= (const Fixed& operand) const;

		Fixed	operator+ (const Fixed& operand) const;
		Fixed	operator- (const Fixed& operand) const;
		Fixed	operator* (const Fixed& operand) const;
		Fixed	operator/ (const Fixed& operand) const;

		Fixed&	operator+= (const Fixed& operand);
		Fixed&	operator-= (const Fixed& operand);
		Fixed&	operator*= (const Fixed& operand);
		Fixed&	operator/= (const Fixed& operand);

		Fixed(void);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed& original);
		Fixed& operator= (const Fixed& fixed);
		~Fixed(void);

	private:
		int					value;
		static const int	bits = 8;
};

std::ostream& operator<< (std::ostream& os, const Fixed& fixed);


#endif
