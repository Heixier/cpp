#ifndef DATA_HPP
#define DATA_HPP

#include <string>

#include <stdint.h>

typedef struct Data
{
	std::string first;
	uintptr_t second;
	std::string third;
} Data;

typedef struct SmallerData
{
	std::string first;
	// missing second and third
} SmallerData;

#endif