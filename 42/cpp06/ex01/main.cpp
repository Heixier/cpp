#include <iostream>
#include <stdint.h>

#include "Serializer.hpp"

int main(void)
{
	Data* never = NULL;
	uintptr_t do_this = 0;

	std::cout << "Original Data ptr address:  " << &never << '\n';
	std::cout << "Original uintptr_t address: " << &do_this << '\n';

	do_this = Serializer::serialize(never);
	std::cout << "Calling deserialize: " << Serializer::deserialize(static_cast<uintptr_t>(do_this)) << '\n';
}