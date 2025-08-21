#include <iostream>

#include "iter.hpp"
#include "info.hpp"

static void increment(int& num)
{
	num += 1;
}

static void print_each(const int& num)
{
	std::cout << num << '\n';
}

static void rot13(char& element)
{
	element -= '0';
	element += 13;
	element = element % 26;
	element += '0';
}

int main(void)
{
	int array[5] = {0, 1, 2, 3, 4};
	const int const_arr[5] = {9, 8, 7, 6, 5};
	char code[7] = "caesar";

	std::cout << "Regular array:\n";
	info(array, 5);

	std::cout << "\nConst array:\n";
	info(const_arr, 5);

	std::cout << "Use increment function on regular array:\n";
	iter(array, 5, increment);

	std::cout << "Use print_each function on const array\n";
	iter(const_arr, 5, print_each);

	info(array, 5);
	info(const_arr, 5);

	std::cout << "\nUse rot13 on " << code << '\n';
	iter(code, 7, rot13);
	std::cout << "after " << code << '\n';

	std::cout << "\nUse rot13 on " << code << '\n';
	iter(code, 7, rot13);
	std::cout << "after " << code << '\n';
}