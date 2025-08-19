#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	switch(rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	Base* test;

	test = dynamic_cast<A*>(p);
	if (test)
	{
		std::cout << "Identified as A!\n";
		return;
	}
	test = dynamic_cast<B*>(p);
	if (test)
	{
		std::cout << "Identified as B!\n";
		return;
	}
	test = dynamic_cast<C*>(p);
	if (test)
	{
		std::cout << "Identified as C!\n";
		return;
	}
	std::cout << "Stop touching my pointers\n";
	return;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Identified as A!\n";
		return;
	}
	catch (const std::exception& e)
	{
		// std::cerr << "Not A, ";
	}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Identified as B!\n";
		return;
	}
	catch (const std::exception& e)
	{
		// std::cerr << "Not B, ";
	}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Identified as C!\n";
		return;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Not a recognised class!\n";
	}
	return;
}

 

int main(void)
{
	Base* dummy;
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << '\n';
		dummy = generate();
		std::cout << std::left << std::setw(11) << "Pointer: ";
		identify(dummy);
		std::cout << std::left << std::setw(11) << "Reference: ";
		identify(*dummy);
		delete dummy;
	}

	Base* hostile = new Base();
	std::cout << '\n' << std::left << std::setw(16) << "Base Pointer: ";
	identify(hostile);

	std::cout << std::left << std::setw(16) << "Base Reference: ";
	identify(*hostile);

	delete hostile;
}