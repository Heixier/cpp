#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "Span.hpp"

void Span::addNumber(int num)
{
	if (idx == num_elements)
		throw std::out_of_range("no more space left in array");
	array[idx++] = num;
}

int Span::shortestSpan()
{
	int smallest_gap = Span::longestSpan();
	int gap = 0;

	if (idx == 1)
		return (0);
	std::sort(array, array + idx);
	for (int i = 0; i + 1 < num_elements; i++)
	{
		gap = array[i + 1] - array[i];
		if (gap <= smallest_gap)
			smallest_gap = gap;
	}
	return (smallest_gap);
}

int Span::longestSpan()
{
	int shortest = *std::min_element(&(array[0]), &(array[idx]));
	int longest = *std::max_element(&(array[0]), &(array[idx]));

	return (longest - shortest);
}

void Span::print_array()
{
	std::cout << "Array length: " << num_elements << "\nArray idx: " << idx << "\n\n";
	for (int i = 0; i < idx; i++)
		std::cout << array[i] << '\n';
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