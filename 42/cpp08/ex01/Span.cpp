#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "Span.hpp"

void Span::addNumber(int num)
{
	if (idx == num_elements)
		throw std::out_of_range("Any attempt to add a new element if there are already N elements stored should throw an exception");
	array[idx++] = num;
}

int Span::shortestSpan()
{
	if (idx <= 1)
		throw std::runtime_error("If there are no numbers stored, or only one, no span can be found. Thus, throw an exception");
	std::sort(array, array + idx);

	int smallest_gap = array[1] - array[0];
	for (int i = 0; i + 1 < idx; i++)
	{
		int gap = array[i + 1] - array[i];
		if (gap < smallest_gap)
			smallest_gap = gap;
	}
	return (smallest_gap);
}

int Span::longestSpan()
{
	if (idx <= 1)
		throw std::runtime_error("If there are no numbers stored, or only one, no span can be found. Thus, throw an exception");
	int shortest = *std::min_element(&(array[0]), &(array[idx]));
	int longest = *std::max_element(&(array[0]), &(array[idx]));

	return (longest - shortest);
}

void Span::print_array()
{
	std::cout << "Array length: " << num_elements << "\nArray idx: " << idx << "\n\n";
	for (int i = 0; i < idx; i++)
		std::cout << i + 1 << ": " << array[i] << '\n';
}

Span::Span(): num_elements(0), idx(0), array(NULL) { }
Span::Span(unsigned int N): num_elements(N), idx(0), array(NULL) { array = new int[num_elements]; }

Span::Span(const Span& other)
{
	num_elements = other.num_elements;
	idx = other.idx;
	array = new int[num_elements];
	for (int i = 0; i < num_elements; i++)
		array[i] = other.array[i];
}

Span& Span::operator= (const Span& other)
{
	if (this != &other)
	{
		num_elements = other.num_elements;
		idx = other.idx;
		delete[] array;
		array = new int[num_elements];
		for (int i = 0; i < num_elements; i++)
			array[i] = other.array[i];
	}
	return (*this);
}

Span::~Span()
{
	delete[] array;
}