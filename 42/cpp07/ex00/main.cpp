#include <iostream>

#include "whatever.hpp"
#include "info.hpp"
#include "Fixed.hpp"

#include "colors.hpp"

void pdf_tests()
{
	std::cout << YELLOW << "TESTS GIVEN BY PDF:\n\n" << END;
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main(void)
{
	pdf_tests();

	std::cout << YELLOW << "\nMY TESTS:\n\n" << END;
	float x = 0.3f;
	float y = 3.9f;

	char a = 'a';
	char b = 'b';

	Fixed p(3.1f);
	Fixed q(-12.2f);

	size_t eq = 42;
	size_t qe = 42;

	std::cout << ICE_BLUE << "TESTING TWO FLOATS: \n\n" << END;
	info(x, y);

	std::cout << ICE_BLUE << "\nTESTING TWO CHARS: \n\n" << END;
	info(b, a);

	std::cout << ICE_BLUE << "\nTESTING TWO FIXED " << YELLOW << "(FROM CPP02)" << ICE_BLUE << ": \n\n" << END;
	info(p, q);

	std::cout << ICE_BLUE << "\nTESTING TWO EQUAL SIZE_T : \n\n" << END;
	info(eq, qe);

}
