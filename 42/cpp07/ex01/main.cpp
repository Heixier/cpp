#include <cctype>
#include <iostream>

#include "iter.hpp"
#include "info.hpp"

#define LIGHT_GREEN "\e[38;5;118;1m"
#define YELLOW "\e[38;5;226;1m"
#define END "\e[0m"

static void increment(int& num)
{
	num += 1;
}

static void print_char(const char& c)
{
	std::cout << c << '\n';
}

static void rot13(char& element)
{
	if (!element)
		return;
	if (std::isupper(element))
	{
		element -= 'A';
		element = (element + 13) % 26;
		element += 'A';
	}
	else
	{
		element -= 'a';
		element = (element + 13) % 26;
		element += 'a';
	}
}

int main(void)
{
	int array[5] = {0, 1, 2, 3, 4};
	const char const_test[6] = "hello";

	std::cout << "Regular int array:\n";
	info(array, 5);

	std::cout << "Use increment function on regular array:\n";
	iter(array, 5, increment);
	info(array, 5);

	std::cout << "\nConst char* array: " << const_test << '\n';
	info(const_test, 5);

	#ifdef NO_CONST_OVERLOAD
	std::cout << "\nUse print_char function on const char* array with no overload" << '\n';
	iter(const_test, 6, print_char);
	std::cout << LIGHT_GREEN << "It works perfectly fine because T resolves to const char\n" << END;

	#else
	std::cout << YELLOW << "\nUse print_char function on const char* array with const overload\n(compile again with 'make overload' for other demo)\n" << END;
	iter(const_test, 6, print_char);

	#endif

	char code[7] = "caesar";

	std::cout << "Use rot13 on char array: \"" << code << "\"\n";
	iter(code, 7, rot13);
	std::cout << "Result: \"" << code << "\"\n";

	std::cout << "\nUse rot13 on char array: \"" << code << "\"\n";
	iter(code, 7, rot13);
	std::cout << "Result: \"" << code << "\"\n";
}